c
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = (char)va_arg(args, int);
				printf("%c", c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				printf("%s", s);
				count += strlen(s);
				while (*format != '\0' && *format != '%')
				{
					format++;
				}
			}
			else if (*format == '%')
			{
				printf("%");
				count++;
			}
			else
			{
				printf("Unknown format specifier: %c\n", *format);
				return (-1);
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
