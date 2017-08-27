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
	//Used in the test/stringwriteTest.c
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

int _makespace(FILE *fp, int pos, int size)
{
	char c;
	int totchars;
	//pos--; //Sets pos accurately
	if(fp == NULL) return 0;
	else
	{
		fseek(fp, 0, SEEK_END);
		totchars = ftell(fp);
		
		if(totchars < pos) return 0; // Can't make freespace after EOF.

		while(totchars >= pos)
		{
			fseek(fp, totchars, SEEK_SET);
			c = fgetc(fp);
			fseek(fp, size-1, SEEK_CUR);
			fputc(c, fp);
			totchars--;
		}
	}
	return 1;
}

int fmakespace(FILE *fp, int pos, int size)
{
	int ret = _makespace(fp, pos, size);
	if(ret == 0) return 0;
	else
	{
		fseek(fp, pos, SEEK_SET);
		while(size--) // Put empty spaces

		{
			fputc(' ', fp);
		}
	}
	return 1;
}

	
int finsert_char(FILE *fp, int pos, char ch)
{
	int ret = _makespace(fp, pos, 1);
	if(ret == 0) return 0;
	else
	{
		if(fp == NULL) return 0;
		else
		{
			fseek(fp, pos, SEEK_SET);
			fputc(ch, fp);
		}
	}
	return 1;
}

int finsert_str(FILE *fp, int pos, char* string)
{
	int ret = _makespace(fp, pos, _strlen(string));
	if(ret == 0) return 0;
	else
	{
		if(fp == NULL) return 0;
		else
		{
			fseek(fp, pos, SEEK_SET);
			fputs(string, fp);
		}
	}
	return 1;
}
