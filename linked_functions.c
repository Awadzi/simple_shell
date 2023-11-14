#include "shell.h"

/**
* list_len - the length of linked list is determined in this function
* @h: first pointer
* Return: list size
*/

size_t list_len(const list_t *h)
{
size_t i = 0;

while (h)
{
h = h->next;
i++;
}
return (i);
}


/**
* list_to_strings - array of strings of list to strings is returned here.
* @head: 1st node
* Return: strings of array are returned
*/

char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t i = list_len(head), j;
char **strs;
char *str;

if (!head || !i)
return (NULL);
strs = malloc(sizeof(char *) * (i + 1));

if (!strs)
return (NULL);

for (i = 0; node; node = node->next, i++)
{
str = malloc(_strlen(node->str) + 1);

if (!str)
{
for (j = 0; j < i; j++)
free(strs[j]);
free(strs);
return (NULL);
}

str = _strcpy(str, node->str);
strs[i] = str;
}
strs[i] = NULL;
return (strs);
}


/**
* print_list - the linked list elements are printed in this function
* @h: first pointer
* Return: list size is returned
*/

size_t print_list(const list_t *h)
{
size_t i = 0;

while (h)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}


/**
* node_starts_with - the string which begins with a prefix is returned here
* @node: pointer to a list
* @prefix: string that will be matched together
* @c: the next character which comes after the prefix to be matched
* Return: a  null or the node matched
*/

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *p = NULL;

while (node)
{
p = starts_with(node->str, prefix);

if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (NULL);
}


/**
* get_node_index - index of a node to be gottted in this function
* @head: where list head points to
* @node: node pointer
* Return: -1 or the node index
*/

ssize_t get_node_index(list_t *head, list_t *node)
{
size_t i = 0;

while (head)
{

if (head == node)
return (i);
head = head->next;
i++;
}
return (-1);
}




