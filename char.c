#include "main.h"
/**
 *char_func - prints strings
 *@p: pointer
 *Return: bytes printed
 */
int char_func(va_list p)
{
	char c = va_arg(p, int);

	return (write(1, &c, 1));
}
