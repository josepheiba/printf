#include "main.h"

/**
 * print_int_space - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_int_space(va_list arg_ptr)
{
	int n, i;
	unsigned int num;
	char minus;
	char space;

	minus = '-';
	space = ' ';

	n = va_arg(arg_ptr, int);
	i = 0;

	i = i + write(1, &space, 1);

	if (n < 0)
	{
		i = i + write(1, &minus, 1);
		num = -n;
	}
	else
		num = n;

	return (print_number(num, i));
}

/**
 * print_percent_2_space - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_percent_2_space(va_list arg_ptr)
{
	char buffer_1_byte;
	char buffer_2_byte;
	(void) arg_ptr;

	buffer_1_byte = '%';
	buffer_2_byte = ' ';
	write(1, &buffer_1_byte, 1);
	write(1, &buffer_2_byte, 1);
	return (2);
}

/**
 * print_percent_space - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_percent_space(va_list arg_ptr)
{
	(void) arg_ptr;
	return (0);
}


