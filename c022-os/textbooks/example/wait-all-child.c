#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int myfork(int childSleepTime);

int main(int argc, char *argv[]) {

    printf("hello world (pid:%d)\n", (int) getpid());
	for (int i = 1; i < 6; i ++) {
        // parent goes down this path (original process)
		myfork(i);
    }
	
	int status = 0;
	int wpid;
	// the parent will waits for all the child processes
	while ((wpid = wait(&status)) > 0) {
        printf("hello, I am parent, (wc:%d) (pid:%d)\n",
	        wpid, (int) getpid());
	}

    return 0;
}

int myfork(int childSleepTime ) {

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d), and parent (ppid:%d)\n",
				(int) getpid(), getppid());
		sleep(childSleepTime);
		if (childSleepTime == 3) {
			exit(-1);
		}
		exit(0);
    } 

	return rc;
}
