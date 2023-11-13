#include "main.h"

/**
 * print_buffer - check code.
 * @format : variable
 * Return: check declaration
 */

int print_buffer(const char *format)
{
	write(1, format, 1);
	return (1);
}

/**
 * print_char - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_char(va_list arg_ptr)
{
	char buffer_1_byte;

	buffer_1_byte = va_arg(arg_ptr, int);
	write(1, &buffer_1_byte, 1);
	return (1);
}

/**
 * print_string - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_string(va_list arg_ptr)
{
	char *buffer_1_byte;
	int i;
	char *nl = "(null)";

	buffer_1_byte = va_arg(arg_ptr, char *);

	if (buffer_1_byte == NULL)
		buffer_1_byte = nl;

	i = 0;

	while (*(buffer_1_byte + i) != '\0')
	{
		write(1, buffer_1_byte + i, 1);
		i++;
	}

	return (i);
}

/**
 * print_percent - check code.
 * @arg_ptr : variable
 * Return: check declaration
 */

int print_percent(va_list arg_ptr)
{
	char buffer_1_byte;
	(void) arg_ptr;

	buffer_1_byte = '%';
	write(1, &buffer_1_byte, 1);
	return (1);
}

/**
 * print_integer - Print an integer to the standard output.
 * @arg_ptr: Variable argument list.
 * Return: Number of characters printed.
*/

int print_integer(va_list arg_ptr)
{
	int num = va_arg(arg_ptr, int);
	int temp = num;
	int digit_count = 0;
	char *buffer;
	int i;

	do 
	{
		temp /= 10;
		digit_count++;
	}
	
	while (temp != 0);
	
	if (num == 0) 
	{
		if (write(1, "0", 1) == -1) 
		{
			return -1;
		}
		return 1;
	}		
		buffer = (char *)malloc(digit_count + 1);
		
		if (buffer == NULL)
		{
			return -1;
		}

		for (i = digit_count - 1; i >= 0; i--)
		{
			buffer[i] = '0' + num % 10;
			num /= 10;
		}
		
		if (write(1, buffer, digit_count) == -1)
		{
			free(buffer);
			return -1;
		}
			free(buffer);
			return digit_count;
}
/**
 * print_decimal - check code.
 * @arg_ptr: variable
 * Return: check declaration
**/

int print_decimal(va_list arg_ptr)
{
	return (print_integer(arg_ptr));
}
