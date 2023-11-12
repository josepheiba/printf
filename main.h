#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

typedef struct print_option
{
        char *specifier;
        int (*function)(va_list);
} print_option;

int _printf(const char *format, ...);
int (*check_a_print(const char *format))(va_list arg_ptr);
int print_buffer_return(va_list arg_ptr);
int print_buffer(const char *format);
int print_char(va_list arg_ptr);
int print_string(va_list arg_ptr);
int print_percent(va_list arg_ptr);

#endif
