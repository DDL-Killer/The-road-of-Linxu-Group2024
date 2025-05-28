#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct strbuf
{
    int len;//buf缓冲区的长度
    int alloc;//buf缓冲区的容量
    char *buf;
};

// 初始化sb结构体，容量为alloc
void strbuf_init(struct strbuf *sb,size_t alloc){
    sb->buf=(char *)malloc(alloc);
    if(sb->buf==NULL){
        sb->alloc=0;
        sb->len=0;
        return;
    }
    sb->alloc=alloc;
    sb->len=0;
    sb->buf[0]='\0';
}

//将字符填充到sb中，长度为len，容量为alloc
void strbuf_attach(struct strbuf *sb,void *str,size_t len,size_t alloc){
    sb->alloc=alloc;
    sb->buf=(char *)str;
    sb->buf[len]='\0';
    sb->len=len;
}
//释放结构体内存
void strbuf_release(struct strbuf *sb){
    free(sb->buf);
    sb->buf=NULL;
    sb->len=0;
    sb->alloc=0;
}
//交换两个strbuf
void strbuf_swap(struct strbuf *a,struct strbuf *b){
    struct strbuf tmp = *a;
    *a = *b;
    *b = tmp;
}

//将sb中的原始内存取出，并且将sz设置为其alloc大小
char *strbuf_detach(struct strbuf *sb,size_t *sz){
    *sz=sb->alloc;
    return sb->buf;
}

//比较两个strbuf的内存是否相同
int strbuf_cmp(const struct strbuf *first,const struct strbuf *second){
    if(first->len!=second->len){
        return first->len-second->len;
    }
    if(first->buf==NULL||second->buf==NULL){
        return (first->buf!=second->buf)? 1:0;
    }
    return memcmp(first->buf,second->buf,first->len);
}

// 清空 sb
void strbuf_reset(struct strbuf *sb){
    if (sb->buf != NULL && sb->alloc > 0) {
        sb->len = 0;
        sb->buf[0] = '\0'; // 确保字符串终止
    }
}

int main(){
    struct strbuf sb;
    strbuf_init(&sb, 10);
    strbuf_attach(&sb, "xiyou", 5, 10);
}

//-----------------------------------------------------------------------------------


//确保len之后至少有extra字节
void strbuf_grow(struct strbuf *sb,size_t extra){
    if((sb->alloc)-(sb->len)<extra){
        sb->buf=realloc(sb->buf,(sb->alloc)+=extra);
    }
}

//向sb追加长度为len的数据data
void strbuf_add(struct strbuf *sb,const void *data,size_t len){
    strbuf_grow(sb,len+1);
    memcpy(sb->buf+sb->len,data,len);
    sb->buf[sb->len+=len]='\0';
}
//向sb追加一个字符c
void strbuf_addch(struct strbuf *sb,char c){
    strbuf_add(sb,&c,1);
}

//向sb追加一个字符串str
void strbuf_addstr(struct strbuf *sb,const char *str){
    strbuf_add(sb,str,strlen(str));
}

//向sb追加另一个strbuf的数据
void strbuf_addbuf(struct strbuf *sb,const struct strbuf *sb2){
    strbuf_add(sb,sb2->buf,sb2->len);
}
//设置sb的长度len
void strbuf_setlen(struct strbuf *sb,size_t len){
    if(len>sb->alloc){
        strbuf_grow(sb,len-sb->len);
    }
    sb->len=len;
    sb->buf[len]='\0';
}

//计算sb目前仍然可以向后追加的字符串的长度
size_t strbuf_avail(const struct strbuf *sb){
    return sb->alloc-sb->len-1;
}

//向sb内存坐标为pos的位置插入长度为len的数据data
void strbuf_insert(struct strbuf *sb,size_t pos,const void *data,size_t len){
    strbuf_setlen(sb,sb->len+len);
    memmove(sb->buf+pos+len,sb->buf+pos,sb->len-pos);
    memcpy(sb->buf+pos,data,len);
}

//-----------------------------------------------------------------------------------

//去除sb缓冲区左端的空格、制表符和‘\t’字符
void strbuf_ltrim(struct strbuf *sb){
    int i=0;
    while(sb->buf[i]==' '||sb->buf[i]=='\t') i++;
    memmove(sb->buf,sb->buf+i,sb->len-i);
    sb->len-=i;
}

//去除sb缓冲区右端的空格、制表符和‘\t’字符
void strbuf_rtrim(struct strbuf *sb){
    int i=sb->len-1;
    while(sb->buf[i]==' '||sb->buf[i]=='\t') i--;
    sb->buf[++i]='\0';
    sb->len=i;
}

//删除sb缓冲区从pos坐标长度为len的内容
void strbuf_remove(struct strbuf *sb,size_t pos,size_t len){
    memmove(sb->buf+pos,sb->buf+pos+len,sb->len-pos-len+1);
}


//----------------------------------
//将文件描述符为fd的所有文件追加到sb，sb增长hint？hint：8192
size_t strbuf_read(struct strbuf *sb,int fd,size_t hint){
    strbuf_grow(sb,hint?hint:8192);
    FILE *fp=fdopen(fd,"r");
    char ch;
    for(;(ch = fgetc(fp))!= EOF;){
        strbuf_addch(sb,ch);
    }
    return sb->len;
}


//将文件句柄为fp的一行内容（抛弃换行符）读取到sb
int strbuf_getline(struct strbuf *sb,FILE *fp){
    char ch;
    for(;ch = fgetc(fp)!=EOF&&ch!='\n';){
        strbuf_addch(sb,ch);
        return sb->len;
    }
}


/**
* @brief 将指定长度的字符串按切割字符切割成多个 strbuf
*
* @param str 要切割的字符串
* @param len 字符串的长度
* @param terminator 切割字符
* @param max 最大切割数量（可选）
* @return struct strbuf** 指向 struct strbuf 的指针数组，数组的最后一个元素为 NULL
*
* @note 函数将字符串 str 根据切割字符 terminator 切割成多个 strbuf，并返回结果。可选参数 max 用于限定最大切割数量。
*/
//-----------------------------------------------------
//1. 将指定长度的字符串按切割字符切割成多个strbuf
struct strbuf** strbuf_split_buf(const char* str, size_t len, int terminator, int max){
    struct strbuf** ret = (struct strbuf**)malloc(sizeof(struct strbuf*)*(max+1));
    for(int pos = 0,flag = 0,n = 0;pos<=len && n<max ;pos++){
        while(str[flag]==terminator)  pos = flag++ + 2;
        if(pos == len || pos>flag && str[pos] == terminator){
            ret[n] = (struct strbuf *)malloc(sizeof(struct strbuf));
            strbuf_init(ret[n],0);
            strbuf_add(ret[n],str+flag,pos-flag);
            while(str[pos] == terminator) flag = pos++;
            ret[++n]=NULL;
        }
    }
    return ret;
}              

/**
* @brief 判断目标字符串是否以指定前缀开头
*
* @param target_str 目标字符串
* @param str 前缀字符串
* @param strlen target_str 的长度
* @return bool 前缀相同返回 true，否则返回 false
*/
bool strbuf_begin_judge(char* target_str, const char* str, int strnlen){
    return str == NULL || !strncmp(target_str,str,strlen(str));
}


/**
* @brief 获取目标字符串的指定子串
*
* @param target_buf 目标字符串
* @param begin 开始下标（包含）
* @param end 结束下标（不包含）
* @param len target_buf 的长度
* @return char* 指向获取的子串的指针，如果参数不合法则返回 NULL
*
* @note 下标从0开始，[begin, end)表示左闭右开区间
*/
char* strbuf_get_mid_buf(char* target_buf, int begin, int end, int len){
    if(begin > end || end>= len) return NULL;
    char* str = (char*)malloc(end-begin+1);
    memcpy(str,target_buf+begin,end-begin);
    str[end - begin]= '\0';
    return str;
}




