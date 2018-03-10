#include<stdio.h>
#include "./../lib/fileutils.h"

int main()
{
	FILE *fp1 = fopen("testpig.txt", "r");
	printf("testpig.txt : %d lines\n", fcountlines(fp1));
	fclose(fp1);

	fp1 = fopen("testpig2.txt", "r");
	printf("testpig2.txt : %d lines\n", fcountlines(fp1));
	fclose(fp1);

	fp1 = fopen("testpig3.txt", "r");
	printf("testpig3.txt : %d lines\n", fcountlines(fp1));
	fclose(fp1);

	fp1 = fopen("testpig4.txt", "r");
	printf("testpig4.txt : %d lines\n", fcountlines(fp1));
	fclose(fp1);

	fp1 = fopen("testpig5.txt", "r");
	printf("testpig5.txt : %d lines\n", fcountlines(fp1));
	fclose(fp1);


	fp1 = fopen("../lib/fileutils.h", "r");
	printf("fileutils.h : %d linees\n", fcountlines(fp1));
	fclose(fp1);

	return 0;
}
