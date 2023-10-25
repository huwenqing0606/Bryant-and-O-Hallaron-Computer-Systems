all: exec \
	 exec/05_exercise_5-1 \
	 exec/05_prefix_sum \
	 exec/08_syscall_write \
	 exec/08_waitpid1 \
	 exec/08_waitpid2 \
	 exec/08_shellex \
	 exec/12_echoservert \

.PHONY: all

exec:
	mkdir -p exec

exec/05_exercise_5-1: 05_exercise_5-1.c
	gcc -o exec/05_exercise_5-1 05_exercise_5-1.c

exec/05_prefix_sum: 05_prefix_sum.c
	gcc -o exec/05_prefix_sum 05_prefix_sum.c

exec/08_syscall_write: 08_syscall_write.c csapp.c
	gcc -o exec/08_syscall_write 08_syscall_write.c csapp.c

exec/08_waitpid1: 08_waitpid1.c csapp.c
	gcc -o exec/08_waitpid1 08_waitpid1.c csapp.c

exec/08_waitpid2: 08_waitpid2.c csapp.c
	gcc -o exec/08_waitpid2 08_waitpid2.c csapp.c

exec/08_shellex: 08_shellex.c csapp.c
	gcc -o exec/08_shellex 08_shellex.c csapp.c

exec/12_echoservert: 12_echoservert.c csapp.c
	gcc -o exec/12_echoservert 12_echoservert.c csapp.c
