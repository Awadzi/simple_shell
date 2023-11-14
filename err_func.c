#include "shell.h"

/**
* _eputs - input string is to be displayed or printed here
* @str: printed string
* Return: should not return anything
*/

void _eputs(char *str)
{
int i = 0;
if (!str)
return;
while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}


/**
* _eputchar - the character  writen to the standard error message
* @c: character we are expected to print
* Return: 1 when it is successful, -1 when it's an error
* and err no when it is set appropriately
*/

int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}


/**
* _putfd - writes the character  to the file descriptor
* @c: character to be printed
* @fd: particular  file descriptor (fd) to write to
* Return: 1 when it is successful, -1 when it's an error
*/

int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
* _putsfd - this fucn is responsible for printing the input string
* @str: printed string
* @fd: the particular file descriptor (fd) we want to write to
* Return: number of characters
*/

int _putsfd(char *str, int fd)
{
int i = 0;
if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}


