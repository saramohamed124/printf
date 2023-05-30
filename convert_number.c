#include "main.h"
/**
 * print_hex - print hex in lower case
 * @ap: va list
 * @params: struct parameter
 * Return: hex
 */

int print_hex(va_list ap, params_t *params)
{
unsigned long l;
int h = 0;
char *s;

if (params->l_modifier)
	l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
	l = (unsigned short int)va_arg(ap, unsigned int);
else
	l = (unsigned int)va_arg(ap, unsigned int);

s = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
if (params->hashtag_flag && l)
{
	*--s = 'x';
	*--s = '0';
}
params->unsign = 1;
return (h += print_number(s, params));
}

/**
 * print_HEX - print HEX in upper case
 * @ap: va list
 * @params: struct parameter
 * Return: hex
 */

int print_HEX(va_list ap, params_t *params)
{
unsigned long l;
int H = 0;
char *s;

if (params->l_modifier)
	l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
	l = (unsigned short int)va_arg(ap, unsigned int);
else
	l = (unsigned int)va_arg(ap, unsigned int);

s = convert(l, 16, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
{
	*--s = 'X';
	*--s = '0';
}
params->unsign = 1;
return (H += print_number(s, params));
}

/**
 * print_binary - print binary case
 * @ap: va list
 * @params: struct parameter
 * Return: binary
 */

int print_binary(va_list ap, params_t *params)
{
unsigned long num = va_arg(ap, unsigned int);
int n = 0;
char *s = convert(num, 2, CONVERT_UNSIGNED, params);

if (params->hashtag_flag && num)
	*--s = '0';
params->unsign = 1;
return (n += print_number(s, params));
}

/**
 * print_octal - print octal case
 * @ap: va list
 * @params: struct parameter
 * Return: octal
 */

int print_octal(va_list ap, params_t *params)
{
unsigned long l;
int o = 0;
char *s;

if (params->l_modifier)
	l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
	l = (unsigned short int)va_arg(ap, unsigned int);
else
	l = (unsigned int)va_arg(ap, unsigned int);
s = convert(l, 8, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
	*--s = '0';
params->unsign = 1;
return (o += print_number(s, params));
}
