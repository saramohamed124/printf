#include "main.h"

/**
 * _printf - printf function 
 * @format: the format string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int s = 0;
	va_list op;
	char *p, *start;

	va_start(op, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)

}
