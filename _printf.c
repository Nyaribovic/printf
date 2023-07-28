i/*
 * File: _printf.c
 * Auth: Victor Bundi,
 *       Chepngetich Brenda.
 *      
 */

#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function that handles c, s, and % conversion specifiers.
 * @format: The format string containing the conversion specifiers.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *c;

    va_start(args, format);
    for (c = format; *c != '\0'; c++)
    {
        if (*c != '%')
        {
            putchar(*c);
            count++;
        }
        else
        {
            c++;
            if (*c == 'c')
            {
                char ch = va_arg(args, int);
                putchar(ch);
                count++;
            }
            else if (*c == 's')
            {
                char *str = va_arg(args, char *);
                while (*str != '\0')
                {
                    putchar(*str);
                    str++;
                    count++;
                }
            }
            else if (*c == '%')
            {
                putchar('%');
                count++;
            }
            else
            {
                putchar('%');
                putchar(*c);
                count += 2;
            }
        }
    }
    va_end(args);

    return count;
}
