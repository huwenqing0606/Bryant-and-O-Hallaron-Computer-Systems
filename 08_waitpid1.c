#include "csapp.h"
#define N 2

int main(){
    int status, i;
    pid_t pid;

    /* Parent creates N children */
    for (i=0; i<N; i++) {
        if ((pid=Fork())==0) /* child */
            exit(100+i);
    }

    printf("Hello World!\n");
}

