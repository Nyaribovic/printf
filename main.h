#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/* Data structure for linked list node */
typedef struct list_s
{
    char *str;
    size_t len;
    struct list_s *next;
} list_t;

/* Function prototypes */
int _printf(const char *format, ...);
size_t print_list(const list_t *h);

#endif /* MAIN_H */
