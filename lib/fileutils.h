/*
 * File Utils library by Yash Yadav
 * Helps working with files in C language where file handling is bare minimum
 * Meaningwise, helps inserting data in the middle(or beginning) of the file

 * FUNCTIONS :
 * _strlen(char*)  :: Local strlength, remove string.h dependency
 * _makespace(const char*, int, int)  :: Pushes all characters foreward to add new content
 * makespace() ::  same as _makespace but puts empty spaces in places instead of existing chars. 
 * finsert_char(const char*, int, char)  :: Insert a single character
 * finsert_string(const char*, int, char*)  ::  Insert a string
 */

void _stdinflush()
{
	char c;
	//Just in case we use fgets() or gets() after a scanf()
	//Used in the stringwriteTest.c
	while((c = getchar()) != '\n' && c!= EOF);
}

int _strlen(char *str)
{
	int inc=0;
	while(str[inc] != '\0')
	{
		inc++;
	}
	return inc;
}

int _makespace(const char *filename, int pos, int size)
{
	FILE *fp = fopen(filename, "r+");
	char c;
	int totchars;
	pos--; //Sets pos accurately
	if(fp == NULL) return 0;
	else
	{
		fseek(fp, 0, SEEK_END);
		totchars = ftell(fp);

		while(totchars >= pos)
		{
			fseek(fp, totchars, SEEK_SET);
			c = fgetc(fp);
			fseek(fp, size-1, SEEK_CUR);
			fputc(c, fp);
			totchars--;
		}
		fclose(fp);
	}
	return 1;
}

int fmakespace(const char *filename, int pos, int size)
{
	int ret = _makespace(filename, pos, size);
	if(ret == 0) return 0;
	else
	{
		FILE *fp = fopen(filename, "r+");
		fseek(fp, pos-1, SEEK_SET);
		while(size--) // Put empty spaces

		{
			fputc(' ', fp);
		}
		fclose(fp);
	}
	return 1;
}

	
int finsert_char(const char *filename, int pos, char ch)
{
	int ret = _makespace(filename, pos, 1);
	if(ret == 0) return 0;
	else
	{
		FILE *fp = fopen(filename, "r+");
		if(fp == NULL) return 0;
		else
		{
			fseek(fp, pos-1, SEEK_SET);
			fputc(ch, fp);
			fclose(fp);
		}
	}
	return 1;
}

int finsert_str(const char* filename, int pos, char* string)
{
	int ret = _makespace(filename, pos, _strlen(string));
	if(ret == 0) return 0;
	else
	{
		FILE *fp = fopen(filename, "r+");
		if(fp == NULL) return 0;
		else
		{
			fseek(fp, pos-1, SEEK_SET);
			fputs(string, fp);
			fclose(fp);
		}
	}
	return 1;
}
