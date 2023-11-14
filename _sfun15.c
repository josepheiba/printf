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
		write(1, buffer_1_byte + j, 1);
		j--;
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
	int i, j;
	char *nl = "(null)";
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	buffer_1_byte = va_arg(arg_ptr, char *);

	if (buffer_1_byte == NULL)
	{
		buffer_1_byte = nl;
		i = 0;

		while (*(buffer_1_byte + i) != '\0')
		{
			write(1, buffer_1_byte + i, 1);
			i++;
		}

		return (i);
	}

	i = 0;

	while (*(buffer_1_byte + i) != '\0')
	{
		j = 0;
		while (input[j] != '\0')
		{
			if (input[j] == buffer_1_byte[i])
			{
				write(1, output + j, 1);
				i++;
				continue;
			}
			j++;
		}
	}

	return (i);
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
	tem = num = (unsigned long)numO;

	if (numO == NULL)
		return (nilly());

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
