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
int c = 0;
char *str;

if (params->l_modifier)
	l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
	l = (unsigned short int)va_arg(ap, unsigned int);
else
	l = (unsigned int)va_arg(ap, unsigned int);

str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
if (params->hashtag_flag && l)
{
	*--str = 'x';
	*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
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
int c = 0;
char *str;

if (params->l_modifier)
	l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
	l = (unsigned short int)va_arg(ap, unsigned int);
else
	l = (unsigned int)va_arg(ap, unsigned int);

str = convert(l, 16, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
{
	*--str = 'X';
	*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}

/**
 * print_binary - print binary case
 * @ap: va list
 * @params: struct parameter
 * Return: binary
 */

int print_binary(va_list ap, params_t *params)
{
unsigned long n = va_arg(ap, unsigned int);
int c = 0;
char *str = convert(n, 2, CONVERT_UNSIGNED, params);

if (params->hashtag_flag && n)
	*--str = '0';
params->unsign = 1;
return (c += print_number(str, params));
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
int c = 0;
char *str;

if (params->l_modifier)
	l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
	l = (unsigned short int)va_arg(ap, unsigned int);
else
	l = (unsigned int)va_arg(ap, unsigned int);
str = convert(l, 8, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
	*--str = '0';
params->unsign = 1;
return (c += print_number(str, params));
}
