#include<stdio.h>
#include "./../lib/fileutils.h"

void _stdinflush()
{
        char c;
        //Just in case we use fgets() or gets() after a scanf()
        while((c = getchar()) != '\n' && c!= EOF);
}

int main()
{
	char filenam[255], string[101];
	int pos;

	printf("Enter filename : ");
	scanf("%s", filenam);

	printf("Enter place : ");
	scanf("%d", &pos);

	_stdinflush();
	
	printf("Enter the string : ");
	fgets(string, 100, stdin);
	string[_strlen(string)-1] = '\0';

	FILE *fp1 = fopen(filenam, "r+");

	int ret = finsert_str(fp1, pos, string);
	if(ret != 0) printf("Written to file.\n");

	fclose(fp1);

	return  0;
}
