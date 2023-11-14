#include "shell.h"


/**
* _erratoi - string is converted to an integer in this function
* @s: the string we are converting
* Return: 0 when there are no numbers in string, else show the converted number
* and a -1 when it;s an error
*/

int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;
if (*s == '+')
s++;
for (i = 0; s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
result *= 10;
result += (s[i] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}


/**
* print_error - I used this function to print an error message
* @info: info structure and paramenter used
* @estr: the string that contains the specified error type
* Return: 0 if there are no numbers in the string, else the converted
* number or a -1 when it;s an error.
*/

void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
* print_d - this function prints a decimal number in an integer format
* @input: input used
* @fd: file descriptor (fd) we are writing to
* Return: the no. of characters that was printed
*/

int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int i, count = 0;
unsigned int _abs_, current;
if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + current / i);
count++;
}
current %= i;
}
__putchar('0' + current);
count++;
return (count);
}


/**
* convert_number - function that converts an int into a string character
* @num: the number value
* @base: the base value
* @flags: the argument flags used
* Return: we are to return the string here
*/

char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;
if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" :
"0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);
if (sign)
*--ptr = sign;
return (ptr);
}


/**
* remove_comments - this function replaces the first
* instance of a comment which is '#' with '\0'
* @buf: the address of the string to be modified
* Return: 0
*/

void remove_comments(char *buf)
{
int i;
for (i = 0; buf[i] != '\0'; i++)
if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
{
buf[i] = '\0';
break;
}
}


