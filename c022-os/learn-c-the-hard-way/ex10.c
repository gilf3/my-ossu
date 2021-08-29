#include <stdio.h>

int main(int argc, char *argv[]) {

	if (argc != 2) {
		printf("ERROR");
		return 1;
	}

	int i = 0;
	for ( i = 0; argv[1][i] != '\0'; i ++) {

		switch (argv[1][i]) {

		case 'a': 
		case 'A':
			printf("%d: 'A'", i);
			break;
		default:
			printf("%c", argv[1][i]);
		}
	}

	return 0;
}
