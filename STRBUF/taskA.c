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
    sb->buf=malloc(alloc);
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
    if(sb->buf){
        free(sb->buf);
    }
    sb->alloc=alloc;
    sb->buf=malloc(sb->alloc);
    memcpy(sb->buf,str,len);
    sb->buf[len]='\0';
    sb->len=len;
}

void strbuf_release(struct strbuf *sb){
    free(sb->buf);
    sb->buf=NULL;
    sb->len=0;
    sb->alloc=0;
}

void strbuf_swap(struct strbuf *a,struct strbuf *b){
    struct strbuf tmp = *a;
    *a = *b;
    *b = tmp;
}

char *strbuf_detach(struct strbuf *sb,size_t *sz){
    char *buf=sb->buf;
    sb->alloc=*sz;
    sb->len=0;
    sb->buf=NULL;
    return buf;
}


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
