#include "main.h"

int print_buffer_return(va_list arg_ptr)
{
	(void) arg_ptr;
	return(0);
}

int print_buffer(const char *format)
{
	write(1, format, 1);
	return(0);
}

int print_char(va_list arg_ptr)
{
	char buffer_1_byte;

	buffer_1_byte = va_arg(arg_ptr, int);
	write(1, &buffer_1_byte, 1);
	return(1);
}

int print_string(va_list arg_ptr)
{
	char *buffer_1_byte;
	int i;
	buffer_1_byte = va_arg(arg_ptr, char *);

	i = 0;

	while (*(buffer_1_byte + i) != '\0')
	{
	write(1, buffer_1_byte + i, 1);
	i++;
	}

	return(1);
}

int print_percent(va_list arg_ptr)
{
	char buffer_1_byte;
	(void) arg_ptr;

	buffer_1_byte = '%';
	write(1, &buffer_1_byte, 1);
	return(1);
}
