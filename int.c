#include "main.h"
/**
 *int_func - deals with printing integers
 *@p: pointer
 *Return: bytes printed
 */
int int_func(va_list p)
{
	char buffer[BUFF_SIZE];
	int i = BUFF_SIZE - 1, length = 0, num = va_arg(p, long int), s = 0;

	buffer[i] = '\0';
	if (num < 0)
	{
		s = 1;
		num *= -1;
	}
	while (num != 0)
	{
		i--;
		buffer[i] = num % 10 + '0';
		num /= 10;
	}
	if (s == 1)
	{
		i--;
		buffer[i] = '-';
	}
	while (buffer[i])
	{
		length++;
		i++;
	}
	i -= length;
	return (write(1, &buffer[i], length));
}
