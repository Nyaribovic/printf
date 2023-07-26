i/*
 * File: _printf.c
 * Auth: Victor Bundi,
 *       Chepngetich Brenda.
 *      
 */

#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int num_chars = 0;
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char ch = va_arg(args, int);
                write(1, &ch, 1);
                num_chars++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char*);
                int len = 0;
                while (str[len] != '\0')
                {
                    len++;
                }
                write(1, str, len);
                num_chars += len;
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                num_chars++;
            }
            else
            {
                /* Invalid conversion specifier, write an error message */
                write(2, "Error: Unknown conversion specifier\n", 36);
                va_end(args);
                return (-1);
            }
        }
        else
        {
            /* Regular character, write it to stdout */
            write(1, format, 1);
            num_chars++;
        }

        format++;
    }

    va_end(args);
    return (num_chars);
}
