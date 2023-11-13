#include "main.h"

/**
 * print_octal - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_octal(va_list arg_ptr)
{
	unsigned int n, m, i, sum;
	unsigned int a[11];
	int count;

	n = va_arg(arg_ptr, unsigned int);
	m = 1073741824; /* (8 ^ 10) */
	a[0] = n / m;

	for (i = 1; i < 11; i++)
	{
		m /= 8;
		a[i] = (n / m) % 8;
	}

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
	return (count);
}

/**
 * print_hex_u - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_hex_u(va_list arg_ptr)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int tem, num;
	char c;

	num = va_arg(arg_ptr, unsigned int);
	tem = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = tem % 16;
		tem /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		c = array[i] + '0';
		write(1, &c, 1);
	}
	free(array);
	return (counter);
}

/**
 * print_hex - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_hex(va_list arg_ptr)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int tem, num;
	char c;

	num = va_arg(arg_ptr, unsigned int);
	tem = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = tem % 16;
		tem /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7 + 32;
		c = array[i] + '0';
		write(1, &c, 1);
	}
	free(array);
	return (counter);
}

/**
 * print_n_string - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_n_string(va_list arg_ptr)
{
	char *buffer_1_byte;
	int i, counter;
	char *nl = "(null)";
	char slash = '\\';
	char ex = 'x';

	buffer_1_byte = va_arg(arg_ptr, char *);

	if (buffer_1_byte == NULL)
		buffer_1_byte = nl;

	i = counter = 0;

	while (*(buffer_1_byte + i) != '\0')
	{
		if (*(buffer_1_byte + i) >= 32 && *(buffer_1_byte + i) < 127)
		{
			write(1, buffer_1_byte + i, 1);
		}
		else
		{
			write(1, &slash, 1);
			write(1, &ex, 1);
			write_hex(*(buffer_1_byte + i));
			counter++;
			counter++;
			counter++;
		}
		i++;
		counter++;
	}

	return (i);
}

/**
 * write_hex - Print an integer to the standard output.
 * @unp: Variable argument list.
 * Return: Number of characters printed.
*/

int write_hex(char unp)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int tem, num;
	char c;

	num = unp;
	tem = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = tem % 16;
		tem /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		c = array[i] + '0';
		write(1, &c, 1);
	}
	free(array);
	return (counter);
}
