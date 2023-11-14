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

/**
 * print_octal_tag - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_octal_tag(va_list arg_ptr)
{
	unsigned int n, m, i, sum;
	unsigned int a[11];
	int count;
	char bigO;

	bigO = '0';

	n = va_arg(arg_ptr, unsigned int);
	m = 1073741824; /* (8 ^ 10) */
	a[0] = n / m;

	if (n == 0)
	{
		write(1, &bigO, 1);
		return (1);
	}

	for (i = 1; i < 11; i++)
	{
		m /= 8;
		a[i] = (n / m) % 8;
	}

	write(1, &bigO, 1);

	for (i = 0, sum = 0, count = 0; i < 11; i++)
	{
		sum += a[i];
		if (sum || i == 10)
		{
		char z = '0' + a[i];

		write(1, &z, 1);
		count++;
		}
	}
	return (count + 1);
}
