#include "shell.h"

/**
*_strchr - a character in a string is being located in this function
* @s: the parsed string
* @c: character we are looking for
* Return: a pointer to the memory area of the parsed string
*/

char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');
return (NULL);
}


/**
*_strncpy - a string is being copied in this function
* @dest: destination we are copying to
* @src: where the string is coming from (source)
* @n: the number of characters copied
* Return: the string copied
*/

char *_strncpy(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
i = 0;
while (src[i] != '\0' && i < n - 1)
{
dest[i] = src[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
}
}
return (s);
}


/**
*_strncat - this fuction is responsible for concatenating 2 strings
* @dest: 1st string
* @src: 2nd string
* @n: amount of bytes used for concatenating this strings
* Return: the string that we've concatenated
*/

char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}
