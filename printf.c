#include "main.h"

int print(char c)
{
	return (write(1, &c, 1));
}


int _printf(const char *format, ...)
{
  int num_args = strlen(format);
  va_list args;
  va_start(args, format);

  int i;

  if (format == NULL)
  {
    return (-1);
  }

  for (i = 0; format[i] != '\0';i++)
  {
    if (format[i] == '%')
    {
      i++;
      if (format[i] == 'c')
      {
        char x = va_arg(args, int);
        print(x);
      }

    }
  }
  va_end(args);
  return 0;
}
