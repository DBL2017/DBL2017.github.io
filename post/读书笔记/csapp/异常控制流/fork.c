#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

static void unix_error(char *msg){
    fprintf(stderr,"%s: %s\n",msg,strerror(errno));
}

static pid_t Fork(void){
    pid_t  pid;
    if((pid=fork())<0){
        unix_error("Fork error");
    }
    return pid;
}

int main(){
    pid_t pid;
    int x=1;
    pid=Fork();
    if (pid==0)
    {
        printf("child: x=%d\n",++x);
        exit(0);
    }

    printf("parent: x=%d\n",--x);
    exit(0);
}