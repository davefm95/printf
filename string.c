#include <unistd.h>
/**
 *string_func - prints a string specified in format string
 *@s: string to be printed
 *Return: num of bytes printed
 */
int string_func(char *s)
{
	int stlen = 0;

	if (s)
	{
		while (s[stlen])
			stlen++;
		return (write(1, s, stlen));
	}
	return (0);
}
