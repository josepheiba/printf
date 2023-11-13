#include "main.h"

/**
 * check_a_print - check the code.
 * @format : variable
 * Return: check the declaration
 */

int (*check_a_print(const char *format))(va_list arg_ptr)
{
	print_option ops[] = {
		{"%c", print_char},
		{"%s", print_string},
		{"%i", print_int},
		{"%d", print_int},
		{"%b", print_bin},
		{"%%", print_percent},
		{"ok", print_buffer_return}
	};
	int i, j;

	i = 0;

	if (format[0] == '%' && format[1] == '\0')
		return (print_none_return);

	while (i < 6)
	{
		j = 0;
		while (format[j] == (ops + i)->specifier[j] && format[j] != '\0')
		{
			j++;
			if ((ops + i)->specifier[j] == '\0')
			{
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

	if (format == NULL)
		return (-1);

	va_start(arg_ptr, format);

	i = 0;
	cnt = pls = 0;
	while (format[i] != '\0')
	{
		pls = check_a_print(format + i)(arg_ptr);
		if (pls == -1)
		{
			pls = print_buffer(format + i);
		}
		else if (pls == -2)
		{
			pls = 0;
		}
		else
		{
			i++;
		}
		cnt += pls;
		i++;
	}
	va_end(arg_ptr);
	if (cnt == 0)
	{
		return (-1);
	}
	return (cnt);
}
