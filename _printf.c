#include "main.h"

/**
 * check_a_print - check the code.
 * @format : variable
 * @frankenstein : variable
 * Return: check declaration
 */

int (*check_a_print(const char *format, int *frankenstein))(va_list arg_ptr)
{
	print_option ops[] = {
		{"%c", print_char},
		{"%s", print_string},
		{"%r", print_rev_string},
		{"%S", print_n_string},
		{"%R", print_r_string},
		{"%i", print_int},
		{"%+i", print_int_plus},
		{"%d", print_int},
		{"%+d", print_int_plus},
		{"%b", print_bin},
		{"%u", print_unsigned},
		{"%o", print_octal},
		{"%x", print_hex},
		{"%p", print_addr},
		{"%X", print_hex_u},
		{"%%", print_percent},
		{"ok", print_buffer_return}
	};
	int i, j;

	i = 0;

	if (format[0] == '%' && format[1] == '\0')
		return (print_none_return);

	while (i < 16)
	{
		j = 0;
		while (format[j] == (ops + i)->specifier[j] && format[j] != '\0')
		{
			j++;
			if ((ops + i)->specifier[j] == '\0')
			{
				*frankenstein = j - 1;
				return ((ops + i)->function);
			}
		}
		i++;
	}
	return ((ops + i)->function);
}

/**
 * _printf - check code.
 * @format : variable
 * Return: check declaration
 */

int _printf(const char *format, ...)
{
	va_list arg_ptr;
	int i;
	long int cnt, pls;
	int *frankenstein;

	va_start(arg_ptr, format);
	if (format == NULL)
		return (-1);

	i = 0;
	cnt = pls = 0;

	if (format[i] == '\0')
		return (0);

	frankenstein = malloc(sizeof(int));
	if (frankenstein == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		pls = check_a_print(format + i, frankenstein)(arg_ptr);
		if (pls == -1)
			pls = print_buffer(format + i);
		else if (pls == -2)
			pls = 0;
		else
			i = i + *frankenstein;
		cnt += pls;
		i++;
	}
	va_end(arg_ptr);
	free(frankenstein);
	if (cnt == 0)
		return (-1);
	return (cnt);
}
