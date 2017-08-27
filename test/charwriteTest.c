#include<stdio.h>
#include "./../lib/fileutils.h"

int main()
{
	char filenam[255], ch;
        int where;

        printf("Enter the name of your file : ");
        scanf("%s", filenam);
	
	FILE *fp1 = fopen(filenam, "r+");
	printf("Enter place and the character to write\n");
	scanf("%d %c", &where, &ch);

	finsert_char(fp1, where, ch);
	fclose(fp1);
	return 0;
}
	
