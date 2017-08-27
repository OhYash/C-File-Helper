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

	FILE *fp1 = fopen(filenam, "r+");

	//making space
	int ret = fmakespace(fp1, where, howlong);

	if(ret == 0)
		printf("File error.\n");
	else
		printf("Done successfully\n");

	fclose(fp1);

	return 0;
}
