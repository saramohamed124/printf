#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

int _printf(const char *format, ...);
void init_params(params_t *params, va_list ap);
int _puts(char *str);
int _putchar(int c);
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
}specifier_t;

typedef struct parameters
{
	unsigned int precision;
}params_t;

#endif
