# Util_string
Basic string library in C

use:  #include "string/str.h"

This library has the same function names from string.h std C.

With some modification

'strcpy' becomes 'str_cpy', for example, and so on... (This library uses underscore in function names);

# Reference

(string.h std C)

The functions are the same as string.h str C, just see the C std library manual.

(There are some other functions that I added)
Char
# Macros
* CHAR_TOLWR(c); // turn c to lower (if not possible c = c);
* CHAR_TOUPR(c); //turn c to upper (if not possible c = c);
*CHAR_ISNUMBER(n); //return 1 if n is a number '0' - '9'
*CHAR_ISALPHA(l); //return 1 if l is 'A' - 'Z' or 'a' - 'z'

# functions

Char

int char_tolower(int);//convert to lower char if is upper
int char_toupper(int); //convert to upper char if is lower
int char_isnumber(int); //return 1 if the char is a number (otherwise: 0)
int char_isalpha(int); //return 1 if the char is A-Z or a-z  (otherwise: 0)

String

int str_trim(char *s);//trim white spaces around the string 's' / returns 0 or 1 if fail or sucess
int str_find(char *a, char *b,int start,int finish); //find 'b' in 'a' at start to finish, if it is found then return
     //its position (returns int);

char *str_msub(const char*orig,int start, int finish);/*malloc*/
//this function above gets a sub string from string 'orig' at start to finish position, returns a new sub string with malloc function. You must free it;

char *str_new(size_t length);/*malloc - allocates a new space for a size length string without initialize it*/

char *str_new_str(const char* s);/*malloc - allocates and initializes a string 's'*/

