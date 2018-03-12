/*
 * File Utils library by Yash Yadav
 * Helps working with files in C language where file handling is bare minimum
 * Meaningwise, helps inserting data in the middle(or beginning) of the file

 * FUNCTIONS :
 * _strlen(char*)  :: Local strlength, remove string.h dependency
 * _makespace(FILE*, int)  :: Pushes all characters foreward to add new content
 * fmakespace(FILE*, int) ::  same as _makespace but puts empty spaces in places instead of existing chars. 
 * finsert_char(FILE*, char)  :: Insert a single character
 * finsert_string(FILE*, char*)  ::  Insert a string
 */

int _strlen(char *str)
{
	int inc=0;
	while(str[inc] != '\0')
	{
		inc++;
	}
	return inc;
}

int _makespace(FILE *fp, int size)
{
	char c;
	int totchars;
	int pos = ftell(fp);
	if(fp == NULL) return -1;
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
	}
	return pos;
}

int fmakespace(FILE *fp, int size)
{
	int pos = _makespace(fp, size);
	if(pos != -1)
	{
		fseek(fp, pos, SEEK_SET);
		while(size--) // Put empty spaces
		{
			fputc(' ', fp);
		}
	}
	return pos;
}

	
int finsert_char(FILE *fp, char ch)
{
	int pos = _makespace(fp, 1);
	if(pos == -1) return -1;
	else
	{
		fseek(fp, pos, SEEK_SET);
		fputc(ch, fp);
	}
	return pos;
}

int finsert_str(FILE *fp, char* string)
{
	int pos = _makespace(fp, _strlen(string));
	if(pos != -1)
	{
		fseek(fp, pos, SEEK_SET);
		fputs(string, fp);
	}
	return pos;
}

int fcountlines(FILE *fp)
{
	int linecount=0;
	fseek(fp, 0, SEEK_SET);
	char ch;
	while(!feof(fp))
	{
		ch = fgetc(fp);
		if(ch == '\n')
			linecount++;
	}
	return linecount;
}

int finsertline(FILE *fp, char *string)
{
	int pos = finsert_str(fp, string);
	if(pos != -1)
	{
		finsert_char(fp, '\n');
	}

	return pos;
}

int fseektoline(FILE *fp, int line)
{
	fseek(fp, 0, SEEK_SET);
	while(!feof(fp) && line>0)
	{
		if(fgetc(fp) == '\n')
			line--;
	}
	return ftell(fp);
}
