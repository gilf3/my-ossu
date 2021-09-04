#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

	int childpid = fork();

	if (childpid == 0) {
		printf("hello\n");
		//printf("%d", getpid());
	} else {
		int w = waitpid(childpid, NULL, 0);
		printf("goodbye\n");
		//printf("%d", w);
	}
}
