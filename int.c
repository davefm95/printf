#include <unistd.h>
#include <limits.h>
/**
 *int_func - prints oit integers
 *@num: integer to be printed
 *Return: num of characters printed
 */
int int_func(int num)
{
	int n, numpow = 1, bytes_prntd = 0;
	char write_char;

	n = num * 10;
	num = n / 10;
	n = num;
	for (; n >= 10; n /= 10)
		numpow *= 10;
	for (; numpow >= 10; numpow /= 10)
	{
		write_char = ((num / numpow) + '0');
		num = num % numpow;
		write(1, &write_char, 1);
		bytes_prntd++;
		if (numpow == 10)
		{
			write_char = num + '0';
			write(1, &write_char, 1);
			bytes_prntd++;
		}
	}
	return (bytes_prntd);
}