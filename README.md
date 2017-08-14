# c_file_utils
Basic file handler utilities lib for c


## WHY?
C language doesn't really have the easiest file handling support, but the base is clean and simple enough that everything is possible with it.

This library is purely help tool to be used when writing to files.

So, here's what you can do with this library out of the box :
	- Add whitespaces in file. Any amount of spaces, at any place.
	- Add a single character anywhere in the file.
	- Add a string anywhere in the file.
C replaces characters and strings when you try to insert them ideally. This allows you to **append** them in the given positions.

So far, this is all, but I plan to add more functions to it.

## How to use
The important file is `fileutils.h` in the lib directory.
Paste this file around your program source and link with
`#include "./path/to/fileutils.h"`

To use this library right away, just go with these functions :

`int fmakespace(const char *filename, int pos, int size)`
...Use this to _add_ `size` number of whitespaces in the `filename` at `pos` position
`int finsert_char(const char *filename. int pos, char ch)`
...Use this to _add_ a character at `pos` position in `filename` file.
`int finsert_str(const char* filename, int pos, char *string)`
...This one to _add_ a string in the middle/beginning of the `filename` file(as per `pos` position)

If Successfully written, all the above functions return 1. 0 is returned in case of any faliure.

----

## Author

This library is written by [Yash Yadav](https://github.com/OhYash).
It's free to use, share and study.

Hit me up -
- [Email](mailto:yashdimpu@gmail.com)
- [Telegram](http://t.me/OhYash)
