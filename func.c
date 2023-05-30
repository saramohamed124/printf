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

/**
 * print_percent - print_percent
 * @ap: va list
 * @params: struct parameter
 * Return: percent
 */
int print_percent(va_list ap, params_t *params)
{
(void)ap;
(void)params;
return (_putchar('%'));
}

/**
 * print_S - print_specifier
 * @ap: va list
 * @params: struct parameter
 * Return: specifier
 */

int print_S(va_list ap, params_t *params)
{
char *s = va_arg(ap, char *);
char *hex;
int su = 0;

if((int)(!s))
	return (_puts(NULL_STRING));

for(; *s; s++)
{
	if ((*s > 0 && *s < 32) || *s >= 127)
	{
		su += _putchar('\\');
		su += _putchar('x');
		hex = convert(*s, 16, 0, params);
		if (!hex[1])
			su += _putchar('0');
		su += _puts(hex);
	}
	else
		su += _putchar(*s);
}
return (su);
}

/**
 * print_int - print_integer
 * @ap: va list
 * @params: struct parameter
 * Return: int
 */
int print_int(va_list ap, params_t *params)
{
long l;

if (params->l_modifier)
	l = va_arg(ap, long);
else if (params->h_modifier)
	l = (short int)va_arg(ap, int);
else
	l = (int)va_arg(ap, int);
return (print_number(convert(l, 10, 0, params), params));
}
