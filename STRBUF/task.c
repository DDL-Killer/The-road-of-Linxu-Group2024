#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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


//-----------------------------------------------------------------------------------

//将文件描述为fd的所有内容追加到sb中，sb增长hint？hint：8192大小
size_t strbuf_read(struct strbuf *sb,int fd,size_t hint){
    if(hint){
        strbuf_grow(sb,hint);
    }else{
        strbuf_grow(sb,8192);
    }
    FILE *fp = fdopen(fd,"r");
    for(char ch;(ch=fgetc(fp)!=EOF);){
        strbuf_addch(sb,ch);
    }
    return sb->len;
}

//将文件句柄为fp的一行内容（抛弃换行符）读取到sb
int strbuf_getline(struct strbuf* sb,FILE *fp){
    for(char ch;(ch=fgetc(fp)!='\n'&&ch!=EOF);){
        strbuf_attch(sb,ch);
    }
}





