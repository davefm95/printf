#include <unistd.h>
/**
 *char_func - prints char types in format string
 *@c: char to be printed
 *Return: num of bytes printed
*/
int char_func(char c)
{
	if (c > 0)
		return (write(1, &c, 1));
	return (0);
}
