#include "main.h"

/* PRINTS CHARACTERS */
/**
 * print_chars - Prints the characters
 * @types: it Lists a of arguments
 * @buffer: array buffer to handle print
 * @flags: Calculates flags that are active
 * @width: the Width
 * @precision: its the Precision specification
 * @size: the size specifiers
 * Return: returns the number of chars printed
 */

int print_chars(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/* PRINTs A STRING */
/**
 * print_str - Prints a string
 * @types: it Lists a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates flags that are active
 * @width: get the width.
 * @precision: its the Precision specification
 * @size: the size specifier
 * Return: returns number of chars printed
 */

int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, k;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (k = width - length; k > 0; k--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (k = width - length; k > 0; k--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/* IT PRINT THE PERCENT SIGN */
/**
 * print_perc - It prints a percent sign
 * @types: it List a of arguments
 * @buffer: array buffer to handle print
 * @flags: it calculates active flags
 * @width: it gets the width.
 * @precision: Precision specification
 * @size: its the size specifier
 * Return: returns number of characters printed
 */

int print_perc(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/* PRINT INTEGER */
/**
 * print_integer - Prints integer
 * @types: it Lists a of arguments
 * @buffer: array buffer to handle print
 * @flags: Calculates flags active
 * @width: it gets the width.
 * @precision: Precision specification
 * @size: its the size specifier
 * Return: returns number of characters printed
 */

int print_integer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	int is_negative = 0;
	long int x = va_arg(types, long int);
	unsigned long int num;

	x = convert_size_number(x, size);

	if (x == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)x;

	if (x < 0)
	{
		num = (unsigned long int)((-1) * x);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}

	k++;

	return (write_number(is_negative, k, buffer, flags, width, precision, size));
}

/* PRINT THE BINARY */
/**
 * print_bin - It Prints an unsigned number
 * @types: the List a of arguments
 * @buffer: array buffer to handle print
 * @flags: Calculates flags active
 * @width: it gets the width.
 * @precision: Precision specification
 * @size: its the size specifier
 * Return: returns the numbers of char printed.
 */

int print_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int x, y, k, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	a[0] = x / y;
	for (k = 1; k < 32; k++)
	{
		y /= 2;
		a[k] = (x / y) % 2;
	}
	for (k = 0, sum = 0, count = 0; k < 32; k++)
	{
		sum += a[k];
		if (sum || k == 31)
		{
			char z = '0' + a[k];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
