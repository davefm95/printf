#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 *_printf - function that prints output
 *@format: format string
 *Return: 0
 */
int _printf(const char *format, ...)
{
	va_list p;
	int i = 0, conv_charswitch = 0;
	va_start(p, format);

	while (format && format[i])
	{
		if (conv_charswitch == 1)
		{
			switch (format[i])
			{
			case '%':
				write(1, &format[i], 1), conv_charswitch--;
				break;
			case 'c':
				char_func(va_arg(p, int)), conv_charswitch--;
				break;
			case 's':
				string_func(va_arg(p, char *)), conv_charswitch--;
				break;
			default:
				write(1, &format[i - 1], 1);
				write(1, &format[i], 1), conv_charswitch--;
			}
			i++;
			continue;
		}
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
			conv_charswitch++;
		i++;
	}
	va_end(p);
	return (0);
}
