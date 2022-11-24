#include "main.h"
/**
 *int_func - function for  integers
 *@p: pointer variable
 *Return: return bytes printed
 */
int int_func(va_list p)
{
	char buffer[BUFF_SIZE];
	int i = BUFF_SIZE - 1, length = 0, num = va_arg(p, long int), s = 0;
	unsigned long int n;

	buffer[i] = '\0';
	if (num == 0)
		buffer[--i] = 0 + '0';
	if (num < 0)
	{
		s = 1;
		buffer[--i] = (-(num % 10)) + '0';
		num /= 10;
		n = (unsigned long int)((num * -1));
	}
	else if (num != 0)
		n = (unsigned long int)num;
	while (n != 0)
	{
		i--;
		buffer[i] = n % 10 + '0';
		n /= 10;
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
