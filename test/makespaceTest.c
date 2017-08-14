#include<stdio.h>
#include "./../lib/fileutils.h"

int main()
{
	char filenam[255];
	int where, howlong;
	
	printf("Enter the name of your file : ");
	scanf("%s", filenam);

	printf("Position and size of space : ");
	scanf("%d %d", &where, &howlong);

	//makeing space
	int ret = makespace(filenam, where, howlong);

	if(ret == 0)
		printf("File error.\n");

	return 0;
}
