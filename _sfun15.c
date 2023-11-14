#include "main.h"

/**
 * print_rev_string - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_rev_string(va_list arg_ptr)
{
	char *buffer_1_byte;
	int i, j;

	buffer_1_byte = va_arg(arg_ptr, char *);
	if (buffer_1_byte == NULL)
		return (-1);

	i = 0;

	while (*(buffer_1_byte + i) != '\0')
	{
		i++;
	}

	j = i - 1;
	while (j >= 0)
	{
		if ((*(buffer_1_byte + j) >= 32 && *(buffer_1_byte + j) < 127)
				|| *(buffer_1_byte + j) == '\n')
		{
			write(1, buffer_1_byte + j, 1);
			j--;
		}
		else
			return (-1);
	}

	return (i);
}

/**
 * print_r_string - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_r_string(va_list arg_ptr)
{
	char *buffer_1_byte;
	int i, j, count;
	char *nl = "(null)";
	char *input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	buffer_1_byte = va_arg(arg_ptr, char *);

	if (buffer_1_byte == NULL)
	{
		buffer_1_byte = nl;
		i = 6;
		write(1, buffer_1_byte, 6);
		return (i);
	}

	count = i = 0;

	while (*(buffer_1_byte + i) != '\0')
	{
		for (j = 0; input[j] != '\0'; j++)
		{
			if (input[j] == buffer_1_byte[i])
			{
				write(1, output + j, 1);
				count++;
				break;
			}
		}
		if ((*(buffer_1_byte + i) < 65) || ((*(buffer_1_byte + i) > 90)
					&& (*(buffer_1_byte + i) < 97)) || (*(buffer_1_byte + i) > 122))
		{
			write(1, buffer_1_byte + i, 1);
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * print_addr - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_addr(va_list arg_ptr)
{
	int i;
	int *array;
	int counter = 0;
	void *numO;
	unsigned long tem, num;
	char c;
	char slash = '0';
	char ex = 'x';

	numO = va_arg(arg_ptr, void *);
	if (numO == NULL)
		return (nilly());

	tem = num = (unsigned long)numO;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	write(1, &slash, 1);
	write(1, &ex, 1);

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
	return (counter + 2);
}

/**
 * nilly - Print an integer to the standard output.
 * Return: Number of characters printed.
*/

int nilly(void)
{
	char *buffer_1_byte = "(nil)";
	int i;

	i = 0;

	while (*(buffer_1_byte + i) != '\0')
	{
		write(1, buffer_1_byte + i, 1);
		i++;
	}
	return (i);
}

/**
 * print_int_plus - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_int_plus(va_list arg_ptr)
{
	int n, i;
	unsigned int num;
	char minus;
	char plus;

	minus = '-';
	plus = '+';

	n = va_arg(arg_ptr, int);
	i = 0;

	if (n < 0)
	{
		i = i + write(1, &minus, 1);
		num = -n;
	}
	else
	{
		i = i + write(1, &plus, 1);
		num = n;
	}

	return (print_number(num, i));
}
