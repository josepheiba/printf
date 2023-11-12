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
	unsigned int cnt, pls;

	if (format == NULL)
		return (-1);

	va_start (arg_ptr, format);

	i = 0;
	cnt = pls = 0;
	while (format[i] != '\0')
	{
		pls = check_a_print(format + i)(arg_ptr);
		if(pls == 0)
		{
			pls = print_buffer(format + i);
		}
		else
		{
			i++;
		}
		cnt += pls;
		i++;
	}
	va_end(arg_ptr);
	return (cnt);
}
