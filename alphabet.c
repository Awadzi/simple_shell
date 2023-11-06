#include "shell.h"

/**
* _isalpha - an alphabet character is checked here
* @c: input character
* Return: 1 when its an alphabet, otherwise 0
*/
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
* interactive - Shell in an interactive mode, should return true value
* @info: The address structure
* Return: In an interactive mode, return 1 otherwise 0
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* _atoi - I used this to convert string into an integer number representation
* @s: converted string
* Return: 0 if there are no numbers in the string, otherwise the converted num
*/
int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;
for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;
if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -result;
else
output = result;
return (output);
}


/**
* is_delim - this is character delimeter function
* @c: checked character
* @delim: string delimeter
* Return: 1 for true, otherwise 0 for false
*/
int is_delim(char c, char *delim)
{
while (*delim)

if (*delim++ == c)
return (1);
return (0);
}
