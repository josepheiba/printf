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

	num = va_arg(arg_ptr, unsigned int);
	tem = num;

	if (num == 0)
		return (zero());

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

	write0X();

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

	num = va_arg(arg_ptr, unsigned int);
	tem = num;

	if (num == 0)
		return (zero());

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

	write0x_();

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
 * write0X - Print an integer to the standard output.
 * Return: Number of characters printed.
*/

void write0X(void)
{
	char bigO, bigX;

	bigO = '0';
	bigX = 'X';
	write(1, &bigO, 1);
	write(1, &bigX, 1);
}

/**
 * write0x_ - Print an integer to the standard output.
 * Return: Number of characters printed.
*/

void write0x_(void)
{
	char bigO, bigX;

	bigO = '0';
	bigX = 'x';
	write(1, &bigO, 1);
	write(1, &bigX, 1);
}

/**
 * zero - Print an integer to the standard output.
 * Return: Number of characters printed.
*/

int zero(void)
{
	char bigO;

	bigO = '0';
	write(1, &bigO, 1);
	return (1);
}
