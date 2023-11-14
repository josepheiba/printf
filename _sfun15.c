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
		buffer_1_byte = nl;

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
