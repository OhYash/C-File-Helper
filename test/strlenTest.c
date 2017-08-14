#include<stdio.h>
#include "./../lib/fileutils.h"

int main()
{
	char string[100];

	printf("Enter string : ");
	fgets(string, 100, stdin);
	printf("Length : %d\n", _strlen(string));

	return 0;
}
