#include "main.h"

/**
 * print_buffer_return - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_buffer_return(va_list arg_ptr)
{
	(void) arg_ptr;
	return (-1);
}

/**
 * print_none_return - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_none_return(va_list arg_ptr)
{
	(void) arg_ptr;
	return (-2);
}

/**
 * print_int - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_int(va_list arg_ptr)
{
	int n, i;
	unsigned int num;
	char minus;

	minus = '-';

	n = va_arg(arg_ptr, int);
	i = 0;

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
 * print_bin - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_bin(va_list arg_ptr)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(arg_ptr, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
		char z = '0' + a[i];

		write(1, &z, 1);
		count++;
		}
	}
	return (count);
}
/**
 * print_unsigned - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_unsigned(va_list arg_ptr)
{
	unsigned int num;

	num = va_arg(arg_ptr, unsigned int);
	if (num == 0)
		return (print_number(num, 0));
	if (num < 1)
		return (-1);
	return (print_number(num, 0));
}
