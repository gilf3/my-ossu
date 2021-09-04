#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int onlyRead();
int main(int argc, char *argv[]) {
	onlyRead();
}

int onlyRead() {

	int fd = open("./sharefd", O_CREAT | O_RDWR);
	if(fd==-1){
      printf("can not open the file\n");
      return 1;
   	}

	int childPid = fork();
	if (childPid < 0) {

		printf("fork failed");
		exit(0);
	} else if (childPid == 0) {

		char buffer[14]={"\0"};
		int len = read(fd, buffer, 14);

		printf("child,%s\nlen=%d\n",buffer,len);

	} else {

		int w = wait(NULL);
		char buffer[14]={"\0"};
		int len = read(fd, buffer, 14);
		printf("parent,%s\nlen=%d\n",buffer,len);
			
		fd = open("./sharefd", O_CREAT | O_RDWR);
		len = read(fd, buffer, 14);
		printf("parent re-open,%s\nlen=%d\n",buffer,len);

		exit(0);
	}

	return 0;
}

int readAndWrite() {

	int fd = open("./sharefd", O_CREAT | O_RDWR);
	if(fd==-1){
      printf("can not open the file\n");
      return 1;
   	}

	int childPid = fork();
	if (childPid < 0) {

		printf("fork failed");
		exit(0);
	} else if (childPid == 0) {

		char name[13] = "StudyTonight";
		write(fd, name, 13);

	} else {

		int fd = open("./sharefd", O_CREAT | O_RDWR);
		int w = wait(NULL);

		char buffer[14]={"\0"};
		int len = read(fd, buffer, 14);

		printf("%s\nlen=%d\n",buffer,len);

		exit(0);
	}

	return 0;
}
