#include "main.h"

int (*check_a_print(const char *format))(va_list arg_ptr)
{
	print_option ops[] =
	{
		{"%c", print_char},
		{"%s", print_string},
		{"%%", print_percent},
		{"ok", print_buffer_return}
	};
	int i, j;
	i = j = 0;

	while (i < 3)
	{
		while (format[j] == (ops + i)->specifier[j])
		{
			j++;
			if ((ops + i)->specifier[j] == '\0')
			{
				return((ops + i)->function);
			}
		}
		i++;
	}
	return((ops + i)->function);
}

int _printf(const char *format, ...)
{
	va_list arg_ptr;
	int i;

	if (format == NULL)
		return (-1);

	va_start (arg_ptr, format);
	
	i = 0;
	while (format[i] != '\0')
	{
		if(check_a_print(format + i)(arg_ptr) == 0)
		{
			print_buffer(format + i);
		}
		else
		{
			i++;
		}
		i++;
	}
	va_end(arg_ptr);
	return (0);
}
