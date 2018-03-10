#include <stdio.h>
#include "../lib/fileutils.h"

int main()
{
	FILE *fp = fopen("testpig.txt", "r+");

//	fseek(fp, 15, SEEK_CUR);
	
	int pos = fseektoline(fp, 1);
	printf("Position after seek : %d\n", pos);

	pos = finsertline(fp, "This is a testline.");
	printf("Pos after insertion : %d\n", pos);

	printf("Total lines now : %d\n", fcountlines(fp));
	
	//int line = 2;
	//
	//fseek(fp, 0, SEEK_SET);
        //while(!feof(fp) && line>0)
        //{
        //        if(fgetc(fp) == '\n')
        //                line--;
	//	printf("%d\n", ftell(fp));
        //}


	return 0;
}
