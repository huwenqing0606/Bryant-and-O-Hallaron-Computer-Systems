/* A simple shell using fork, execve, waitpid */

#include "csapp.h"
#define MAXARGS 128

/* Function Prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

int main(){
    char cmdline[MAXLINE]; /* Command line */

    while (1){
        /* Read */
        printf("> ");
        Fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin))
            exit(0);
        
        /* Evaluate */
        eval(cmdline);
    }
}

/* eval - Evaluate a command line */
void eval(char *cmdline) {
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE]; /* Holds modified command line */
    int bg; /* Should the job done in bg or fg? */
    pid_t pid; /* Process id */

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    
    if (argv[0] == NULL)
        return; /* Ignore empty lines */

    if (!builtin_command(argv)) {
        if ((pid=Fork())==0) { /* Child runs user job */
            if (execve(argv[0], argv, environ)<0) {
                printf("%s: Command not found. \n", argv[0]);
                exit(0);
            }
        }
        
        /* Parent waits for foreground job to terminate */
        if (!bg) {
            int status;
            if (waitpid(pid, &status, 0)<0)
                unix_error("waitfg: waitpid error");
        }
        else
            printf("%d %s", pid, cmdline);
    }
    return;
}

/* if first arg is a builtin command, run it and return true */
int builtin_command(char **argv) {
    if (!strcmp(argv[0], "quit"))   /* quit command */
        exit(0);
    if (!strcmp(argv[0], "&"))  /* Ignore & */
        exit(0);
    return 0; /* Not a built-in command */
}

/* parse the command line and build the argv array */
int parseline(char *buf, char **argv){
    char *delim; /* points to first space delimiter */
    int argc; /* Number of args */
    int bg; /* Background job? */

    buf[strlen(buf)-1] = ' '; /* Replace trailing '\n' with space */
    while (*buf && (*buf==' '))
        buf++;
    
    /* Build the argv list */
    /* split buf by ' ', core logic */
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++]=buf;
        *delim='\0';
        buf=delim+1; /* move buf to point to the next arg */
        while (*buf && (*buf==' ')) 
            buf++;
    }
    argv[argc]=NULL;

    if (argc==0)
        return 1;

    /* Should the job run in background? */
    if ((bg=(*argv[argc-1]=='&'))!=0)
        argv[--argc]=NULL;

    return bg;
}