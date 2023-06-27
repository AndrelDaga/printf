#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
int _putchar(char c);
char *inttostr(int num);
int _putstr(char *s);
int _putint(int x);
void case_char(va_list args, int *i, int *n_c);
void case_str(va_list args, int *i, int *n_c);
void case_mod(const char *format, int *i, int *n_c);
void case_int(va_list args, int *i, int *n_c);
void case_default(const char *format, int *i, int *n_c);
#endif
