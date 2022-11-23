#include "main.h"
/**
 *_printf - personal implementation of printf func
 *@format: format string
 *Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i, conv_charswitch = 0,  bytes_prntd = 0;
	va_list p2arg;

	if (format == NULL)
		return (-1);
	va_start(p2arg, format);
	for (i = 0; format[i]; i++)
	{
		if (conv_charswitch == 1)
		{
			bytes_prntd += print_func(format[i], p2arg);
			conv_charswitch--;
			continue;
		}
		if (format[i] != '%')
			bytes_prntd += write(1, &format[i], 1);
		else
			conv_charswitch++;
	}
	return (bytes_prntd);
}
