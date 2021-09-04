#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int myfork(int childSleepTime);

int main(int argc, char *argv[]) {

    printf("hello world (pid:%d)\n", (int) getpid());

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d), and parent (ppid:%d)\n",
				(int) getpid(), getppid());
		sleep(3);
		// 
        printf("hello, I am orphan (pid:%d), and parent (ppid:%d)\n",
				(int) getpid(), getppid());
    } else {
		sleep(1);
		exit(0);
	}

    return 0;
}

