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
 * find_num_bits - Print an integer to the standard output.
 * @n: Variable argument list.
 * Return: Number of characters printed.
*/

int find_num_bits(int n)
{
	int count;

	count = 0;

	while (n != 0)
	{
		n >>= 1;
	count++;
	}
	return (count);
}

/**
 * print_bin - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_bin(va_list arg_ptr)
{

	int i, n, size;
	char *binary;

	n = va_arg(arg_ptr, int);

	size = find_num_bits(n);
	binary = malloc(size * sizeof(char));
	size = (size == 0) ? 1 : size;
	binary[size] = '\0';

	for (i = size - 1; i >= 0; i--)
	{
		binary[i] = (n & 1) + '0';
	n >>= 1;
	}
	return (write(1, binary, size));
	free(binary);
}
