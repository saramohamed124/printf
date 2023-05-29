#include "main.h"

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return: void
 */
int _puts(char *str)
{
char *a = str;

while (*str)
_putchar(*str++);
return (str - a);
}

/**
 * _putchar - writes the character c to sdout
 * @c: The character to print
 *
 * Return: On success 1
 * On error, -1 is returned, and errno is set appro
 */
int _putchar(int c)
{
static int i;
static char buf[OUTPUT_BUF_SIZE];

if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
{
write(l, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (l);
}
