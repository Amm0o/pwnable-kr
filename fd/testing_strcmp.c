#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]) {

	if (argc != 2) {
		printf("Please insert a string to compare \n");
		return -1;
	}

	if(!strcmp("test", argv[1])) {
		printf("True \n");
		return 0;
	} 

	char testingIO[100];
	fgets(testing);

	prtinf("Output of testingIO: %s", testingIO);
	
	printf("False \n");
	return -1;
}
