#include "main.h"

/**
 * print_unsig - Prints unsigned numbers
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates flags active
 * @width: it gets width
 * @precision: its the precision specification
 * @size: the size specifier
 * Return: returns number of chars printed.
 */

int print_unsig(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsg(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}

	k++;

	return (print_unsgnd(0, k, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints unsigned numbers in octal notation
 * @types: the Lista of arguments
 * @buffer: array buffer to handle print
 * @flags: Calculates flags active
 * @width: it gets width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: returns number of characters printed
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsg(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[k--] = '0';

	k++;

	return (print_unsgnd(0, k, buffer, flags, width, precision, size));
}

/**
 * print_hex - Prints unsigned numbers in hexadecimal notation
 * @types: the Lista of arguments
 * @buffer: array buffer to handle print
 * @flags: Calculates flags active
 * @width: it gets width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: returns number of characterss printed
 */

int print_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hex_upper - Prints unsigned numbers in upper hexadecimal notation
 * @types: The Lista of arguments
 * @buffer: array buffer to handle print
 * @flags: Calculates flags active
 * @width: it gets width
 * @precision: the Precision specification
 * @size: the Size specifier
 * Return: returns number of characters printed
 */

int print_hex_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints hexadecimal numbers in lower or upper
 * @types: the Lista of arguments
 * @map_to: value array to map the number to
 * @buffer: array buffer to handle print
 * @flags: Calculates flags active
 * @flag_ch: Calculates active flags
 * @width: it gets width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: returns number of characters printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsg(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[k--] = flag_ch;
		buffer[k--] = '0';
	}

	k++;

	return (print_unsgnd(0, k, buffer, flags, width, precision, size));
}
