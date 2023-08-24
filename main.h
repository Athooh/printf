#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS FUNCTIONS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16


#define S_LONG 2
#define S_SHORT 1

/**
 * struct frmt - The Struct operators
 *
 * @frmt: its the format.
 * @fn: This is the function associated.
 */

struct frmt
{
	char frmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct frmt frmt_t - The Struct operators
 *
 * @frmt: its the format.
 * @frmt_t: The is the function associated.
 */

typedef struct frmt frmt_t;

int _printf(const char *format, ...);
int argument_print(const char *frmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


/* chars and strings print function */
int print_chars(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_perc(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Print Numbers Functions */
int print_integer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsig(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hex_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* non printable characters print function */
int print_non_printables(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* other specifiers function hundler */
int print_flags(const char *format, int *i);
int print_width(const char *format, int *i, va_list list);
int print_precision(const char *format, int *i, va_list list);
int print_size(const char *format, int *i);

/* string in reverse print function */
int print_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* string in rot 13 print function */
int print_rot13str(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler function */

int handle_write_chars(char c, char buffer[],
	int flags, int width, int precision, int size);
int print_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int print_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int print_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int print_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/* UTILITIES */
int is_printables(char);
int append_hex_code(char, char[], int);
int is_dgt(char);

long int convert_size_num(long int num, int size);
long int convert_size_unsg(unsigned long int num, int size);

#endif
