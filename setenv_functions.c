#include "shell.h"

/**
* _getenv - the envion variable can be gotten from this function
* @info: Structure used for function prototype & arguments
* @name: environ name
* Return: the final value
*/

char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;
while (node)
{
p = starts_with(node->str, name);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}


/**
* _myenv - current environment is printed using this function
* @info: Structure used for function prototype & arguments
* Return: 0
*/

int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}


/**
* _mysetenv - new environ is initialized or existing one is modified
* @info: Structure used for function prototype & arguments
* Return: 0
*/

int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguments here\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}


/**
* _myunsetenv - environ variable is removed with this function
* @info: Structure used for function prototype & arguments
* Return: 0
*/

int _myunsetenv(info_t *info)
{
int i;
if (info->argc == 1)
{
_eputs("arguments not much.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_unsetenv(info, info->argv[i]);
return (0);
}


/**
* populate_env_list - the environ linked list is being populated here
* @info: Structure used for function prototype & arguments
* Return: 0
*/

int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i;
for (i = 0; environ[i]; i++)
add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}


