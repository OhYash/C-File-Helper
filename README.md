# C File Helper
Basic file writing helper library library for c  

## WHY?
C language doesn't really have the easiest file handling support, but the base is clean and simple enough that everything is possible with it.

This library is purely help tool to be used when writing to files.

So, here's what you can do with this library out of the box :
- Add whitespaces in file. Any amount of spaces, at any place.
- Add a single character anywhere in the file.
- Add a string anywhere in the file.
- Add a line in the middle of a file.
- Seek to any line in a file.
- Count the number of lines in a file.   
C replaces characters and strings when you try to insert them ideally. This allows you to **insert** them in the given positions.

So far, this is all, but I plan to add more functions to it.

## How to use
The important file is [fileutils.h](/lib/fileutils.h) in the [lib](/lib) directory.
Paste this file around your program source and link with
```c
#include "./path/to/fileutils.h"
```

To use this library right away, just go with these functions :

```c
int fmakespace(FILE *fp, int size) 
```
Use this to _add_ `size` number of whitespaces in the `fp` (file pointer) at already seeked position   
```c
int finsert_char(FILE *fp, char ch) 
```
Use this to _add_ a character at seeked position in `fp` file.   
```c
int finsert_str(FILE *fp, char *string)
```
This one to _add_ a string in the middle/beginning of the `fp` file as per the position   
```c
int finsertline(FILE *fp, char *string)
```
This inserts a line from the current position of the file pointer.   
```c
int fseektoline(FILE *fp, int line)
```
This allows for quick seeking to any line number (line indexing from 0).    
```c
int fcountlines(FILE *fp)
```
This simply returns the number of lines in a file.   

> All the above functions return the integer position of the beginning of char/string/whitespace after successful completion and return -1 in case of any faliure.

----

## Author

This library is written by [Yash Yadav](https://github.com/OhYash).
It's free to use, share and study.

Hit me up -
- [Email](mailto:yashyadav.710@outlook.com)
- [Telegram](http://t.me/OhYash)
