#include "main.h"

/**
 * print_hex_u_tag - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_hex_u_tag(va_list arg_ptr)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int tem, num;
	char c;
	char bigO;
	char bigX;

	bigO = '0';
	bigX = 'X';

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

	write(1, &bigO, 1);
	write(1, &bigX, 1);

	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		c = array[i] + '0';
		write(1, &c, 1);
	}
	free(array);
	return (counter + 2);
}

/**
 * print_hex_tag - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_hex_tag(va_list arg_ptr)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int tem, num;
	char c;
	char bigO;
	char bigX;

	bigO = '0';
	bigO = 'x';

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

	write(1, &bigO, 1);
	write(1, &bigX, 1);

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

