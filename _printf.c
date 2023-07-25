#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int num_chars = 0;
    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int);
                    write(1, &c, sizeof(char));
                    num_chars++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    int len = 0;
                    while (str[len]) len++;
                    write(1, str, len);
                    num_chars += len;
                    break;
                }
                case '%': {
                    char percent = '%';
                    write(1, &percent, sizeof(char));
                    num_chars++;
                    break;
                }
                default:
                    write(2, "Error: Unknown conversion specifier\n", 36);
                    va_end(args);
                    return(-1);
            }
        } else {
            write(1, format, sizeof(char));
            num_chars++;
        }

        format++;
    }

    va_end(args);
    return (num_chars);
}

/* Test the function*/
int main() {
    int result = _printf("Hello, %s! Today is %c.\n", "Alice", 'S');
    _printf("Number of characters printed: %d\n", result);
    return (0);
}

