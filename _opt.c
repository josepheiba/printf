#include "main.h"

/**
 * print_buffer - check code.
 * @format : variable
 * Return: check declaration
 */

int print_buffer(const char *format)
{
	write(1, format, 1);
	return (1);
}

/**
 * print_char - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_char(va_list arg_ptr)
{
	char buffer_1_byte;

	buffer_1_byte = va_arg(arg_ptr, int);
	write(1, &buffer_1_byte, 1);
	return (1);
}

/**
 * print_string - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_string(va_list arg_ptr)
{
	char *buffer_1_byte;
	int i;
	char *nl = "(null)";

	buffer_1_byte = va_arg(arg_ptr, char *);

	if (buffer_1_byte == NULL)
		buffer_1_byte = nl;

	i = 0;

	while (*(buffer_1_byte + i) != '\0')
	{
		write(1, buffer_1_byte + i, 1);
		i++;
	}

	return (i);
}

/**
 * print_percent - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_percent(va_list arg_ptr)
{
	char buffer_1_byte;
	(void) arg_ptr;

	buffer_1_byte = '%';
	write(1, &buffer_1_byte, 1);
	return (1);
}

/**
 * print_int - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_int(va_list arg_ptr)
{
	int n, t, l;
	unsigned int num;
	char minus, cum;

	minus = '-';

	n = va_arg(arg_ptr, int);
	t = 1;
	l = 0;

	if (n < 0)
	{
		l = l + write(1, &minus, 1);
		num = -n;
	}
	else
		num = n;

	while (num / t > 9)
		t = t * 10;

	while (t != 0)
	{
		cum = '0' + num / t;
		l = l + write(1, &cum, 1);
		num = num % t;
		t = t / 10;
	}

	return (l);
}
