#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int shared = 100;
	int childPid = fork();
	if (childPid < 0) {

		printf("fork failed");
		exit(0);
	} else if (childPid == 0) {

        printf("child (pid:%d), shared var %d\n",
				(int) getpid(), shared);
		shared++;
        printf("child (pid:%d), shared var %d after increase\n",
				(int) getpid(), shared);

		while (shared < 500) {
			shared ++;
			sleep(1);
        	printf("child (pid:%d), shared var %d keep increase\n",
				(int) getpid(), shared);
		}
        printf("child (pid:%d), i am done\n", (int) getpid() );

	} else {


		while (shared > -50) {
			shared --;
			sleep(1);
        	printf("pareant, shared var %d keep decrease\n", shared);
		}

		int w = wait(NULL);
		exit(0);
	}

	return 0;
}
