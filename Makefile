all:	exec/05_exercise_5-1 \
		exec/05_prefix_sum \
	 	exec/08_syscall_write \
		exec/08_waitpid1 \

PHONY: all

exec/05_exercise_5-1: 05_exercise_5-1.c
	gcc -o exec/05_exercise_5-1 05_exercise_5-1.c

exec/05_prefix_sum: 05_prefix_sum.c
	gcc -o exec/05_prefix_sum 05_prefix_sum.c

exec/08_syscall_write: 08_syscall_write.c csapp.c
	gcc -o exec/08_syscall_write 08_syscall_write.c csapp.c

exec/08_waitpid1: 08_waitpid1.c csapp.c
	gcc -o exec/08_waitpid1 08_waitpid1.c csapp.c