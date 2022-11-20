#include <unistd.h>
/**
 *char_func - prints char types in format string
 *@c: char to be printed
 */
void char_func(char c)
{
	write(1, &c, 1);
}
