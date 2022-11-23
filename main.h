#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFF_SIZE 1024
typedef struct charfunc
{
	char c;
	int (*pr)(va_list p);
}print_f;
int _printf(const char *format, ...);
int print_func(char c, va_list p);
int char_func(va_list p);
int string_func(va_list p);
int int_func(va_list p);
#endif
