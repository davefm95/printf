#include "main.h"
int string_func(va_list p)
{
	char *s = va_arg(p, char *);
	int length = 0;

	if (s)
	{
		while (s[length])
			length++;
		return (write(1, s, length));
	}
	return (write(1, "(null)", 6));
}
