#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void sigint_handler(int sig){
    printf("Caught SIGINT!\n");
    exit(0);
}

int main(){
    if (signal(SIGINT,sigint_handler)==SIG_ERR){
        printf("SIG_ERR\n");
    }
    pause();
    return 0;
}