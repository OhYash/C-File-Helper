#include<stdio.h>
#include "./../lib/fileutils.h"

int main()
{
	char filenam[255], ch;
        int where;

        printf("Enter the name of your file : ");
        scanf("%s", filenam);

	printf("Enter place and the character to write\n");
	scanf("%d %c", &where, &ch);

	finsert_char(filenam, where, ch);
	return 0;
}
	
