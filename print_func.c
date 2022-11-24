#include "main.h"
/**
 *print_func - function that handles the selection of appropriate function
 *@c: character of the format specifier
 *@p: a va_list pointer
 *Return: return nytes printed
 */
int print_func(char c, va_list p)
{
	int i, bytes_prntd = 0;
	print_f struct_arr[] = {{'c', char_func}, {'s', string_func},
				{'d', int_func}, {'i', int_func}, {'\0', NULL}};

	for (i = 0; struct_arr[i].c != '\0'; i++)
	{
		if (struct_arr[i].c == c)
			return (struct_arr[i].pr(p));
	}
	if (c == '\0')
		return (-1);
	bytes_prntd += write(1, "%", 1);
	if (c != '%')
		bytes_prntd += write(1, &c, 1);
	return (bytes_prntd);
}
