#include "main.h"
int int_func(va_list p)
{
	char buffer[BUFF_SIZE];
	int i = BUFF_SIZE - 1, length = 0, num = va_arg(p, long int);;

	buffer[i] = '\0';
	while (num != 0)
	{
		i--;
		buffer[i] = num % 10 + '0';
		num /= 10;
	}
	while (buffer[i])
	{
		length++;
		i++;
	}
	i -= length;
	return (write(1, &buffer[i], length));
}
