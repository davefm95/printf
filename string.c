#include <unistd.h>
/**
 *string_func - prints a string specified in format string
 *s: string to be printed
 */
void string_func(char *s)
{
	int stlen = 0;

	if (s)
	{
		while (s[stlen])
			stlen++;
		write(1, s, stlen);
	}
}
