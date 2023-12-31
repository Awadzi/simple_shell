#include "shell.h"

/**
* _myalias - I used this function to mimic the builtin alias function
* @info: Structure used for function prototype & arguments
* Return: 0
*/
int _myalias(info_t *info)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;
if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
p = _strchr(info->argv[i], '=');
if (p)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}
return (0);
}

/**
* unset_alias - The alias is set to string to execute this function
* @info: the structure parameter
* @str: alias strng
* Return: 0 when it:s a success &  error when it's 1
*/
int unset_alias(info_t *info, char *str)
{
char *p, c;
int ret;
p = _strchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = c;
return (ret);
}

/**
* set_alias - This is used to set string alias
* @info: structure parameter
* @str: alias string
* Return: 0 when it is a success & error when 1
*/

int set_alias(info_t *info, char *str)
{
char *p;
p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}


/**
* print_alias - alias string is to be printed in this function
* @node: node alias
* Return: 0 when it is a success & error when it is 1
*/

int print_alias(list_t *node)
{
char *p = NULL, *a = NULL;
if (node)
{
p = _strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}


