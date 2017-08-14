#include<stdio.h>
#include "./../lib/fileutils.h"

int main()
{
	char filenam[255], string[50];
	int pos;

	printf("Enter filename : ");
//	fgets(filenam, 255, stdin);
	scanf("%s", filenam);

	printf("Enter place : ");
	scanf("%d", &pos);

	printf("Enter the string : ");
	_stdinflush();
	fgets(string, 50, stdin);
	string[_strlen(string)-1] = '\0';
	//scanf("%s", string);

	int ret = finsert_str(filenam, pos, string);
	if(ret != 0) printf("Written to file.\n");

	return  0;
}
