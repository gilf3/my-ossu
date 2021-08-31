#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int i;
	for (i = 1; i < argc; i ++) {

		FILE* fd = fopen(argv[i], "r");
		if (fd == NULL) {
			printf("wcat: cannot open file\n");
			exit(1);
		}
		//printf("open file ok %s", argv[1]);
		char *line = NULL;
		size_t len;
		while (getline(&line, &len, fd) != -1) {
			printf("%s", line);
		}

		fclose(fd);
	}

	return 0;
}
