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
	int i = 0, conv_charswitch = 0, no_bytes = 0;
	char *st;

	va_start(p, format);
	while (format && format[i])
	{
		if (conv_charswitch == 1)
		{
			switch (format[i])
			{
			case '%':
				no_bytes += write(1, &format[i], 1), conv_charswitch--;
				break;
			case 'c':
				no_bytes += char_func(va_arg(p, int)), conv_charswitch--;
				break;
			case 's':
				st = va_arg(p, char *);
				no_bytes += string_func(st), conv_charswitch--;
				break;
			case 'd':
			case 'i':
				no_bytes += int_func(va_arg(p, int)), conv_charswitch--;
				break;
			default:
				no_bytes += write(1, &format[i - 1], 1);
				no_bytes += write(1, &format[i], 1), conv_charswitch--;
			}
			i++;
			continue;
		}
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			no_bytes += 1;
		}
		else
			conv_charswitch++;
		i++;
	}
	va_end(p);
	return (no_bytes);
}
