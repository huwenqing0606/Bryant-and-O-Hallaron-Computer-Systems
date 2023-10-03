all : exec/08_syscall_write exec/08_waitpid1
PHONY : all

exec/08_syscall_write: 08_syscall_write.c csapp.c
	gcc -o exec/08_syscall_write 08_syscall_write.c csapp.c -lpthread

exec/08_waitpid1: 08_waitpid1.c csapp.c
	gcc -o exec/08_waitpid1 08_waitpid1.c csapp.c -lpthread