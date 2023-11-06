#include "shell.h"

/**
* _mycd - use to change curent working dirctory of process environment
* @info: Structure used for function prototype & arguments
* Return: 0
*/
int _mycd(info_t *info)
{
char *s, *dir, buffer[1024];
int chdir_ret;
s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: >>We get current working dir. failure emailMsg here<<\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
chdir_ret = /**Change Directory**/
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = /**Change Directory**/
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_error(info, "Error, you can not cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}


/**
* _myhelp - function that changes current directory of process environment
* @info: Structure used for function prototype & arguments
* Return: 0
*/

int _myhelp(info_t *info)
{
char **arg_array;
arg_array = info->argv;
_puts("The help call works here, when function is yet to be implemented \n");
if (0)
_puts(*arg_array);
return (0);
}


/**
* _myexit - This is used to exits shell
* @info: Structure used for function prototype & arguments
* Return: An exit status (0) if info.argv (value)= 0 and not exit
*/
int _myexit(info_t *info)
{
int exitcheck;
if (info->argv[1])
{
exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "An illegal num: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}


/**
* _myhistory - history list which starts with 0 & starts with line numbers
* @info: Structure used for function prototype & arguments
* Return: 0
*/
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}


