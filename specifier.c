#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 * Return: the number of bytes printed
 */

int (*get_specifier(char *s)) (va_list ap, params_t *params)
{
specifier_t specifiers[] = {
	{"c", print_char},
	{"d", print_int},
	{"i", print_int},
	{"s", print_string},
	{"%", print_percent},
	{"S", print_S},
	{"b", print_binary},
	{"o", print_octal},
	{"u", print_unsigned},
	{"x", print_hex},
	{"X", print_HEX},
	{"p", print_address},
	{"r", print_rev},
	{"R", print_rot13},
	{NULL, NULL}
};
int i = 0;

while (specifiers[i].specifier[0])
{
	if (*s == specifiers[i].specifier[0])
	{
		return (specifiers[i].f);
	}
	i++;
}
return (NULL);
}
/**
 * get_print_func - finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: the number of byets printed
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
int (*f)(va_list, params_t *) = get_specifier(s);
if (f)
return (f(ap, params));
return (0);
}
