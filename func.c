#include "main.h"
/**
 * print_char - print_char
 * @ap: va list
 * @params: struct parameter
 * Return: char
 */
int print_char(va_list ap, params_t *params)
{
char padding = ' ';
unsigned int pad_c = 1, s = 0, c = va_arg(ap, int);

if (params->minus_flag)
	s += _putchar(c);
while (pad_c++ < params->width)
	s += _putchar(padding);
if (!params->minus_flag)
	s += _putchar(c);
return (s);
}

/**
 * print_string - print_string
 * @ap: va list
 * @params: struct parameter
 * Return: string
 */

int print_string(va_list ap, params_t *params)
{
char padding = ' ', *s = va_arg(ap, char *);
unsigned int pad_s = 0, su = 0, i = 0, j;

(void)params;
switch ((int)(!s))
{
case 1 :
	s = NULL_STRING;
	break;
}
j = pad_s = strlen(s);
if (params->precision < pad_s)
	j = pad_s = params->precision;
if (params->minus_flag)
{

	if (params->precision != UINT_MAX)
		for (i = 0; i < pad_s; i++)
			su += _putchar(*s++);
	else
		su += _puts(s);
}

while (j++ < params->width)
	su += _putchar(padding);
if (!params->minus_flag)
{
	if (params->precision != UINT_MAX)
		for (i = 0; i < pad_s; i++)
			su += _putchar(*s++);
	else
		su += _puts(s);
}
return (su);
}
