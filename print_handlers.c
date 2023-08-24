#include "main.h"

/**
 * handle_write_chars - it prints string
 * @c: character types.
 * @buffer: array buffer to handle print
 * @flags: Calculates flags active.
 * @width: it gets width.
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: returns number of characters printed.
 */

int handle_write_chars(char c, char buffer[],
	int flags, int width, int precision, int size)
{ 
	int k = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[k++] = c;
	buffer[k] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (k = 0; k < width - 1; k++)
			buffer[BUFF_SIZE - k - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - k - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - k - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * print_number - it prints a string
 * @is_negative: the Lista of arguments
 * @ind: characters types.
 * @buffer: array buffer to handle print
 * @flags: Calculates flags active
 * @width: it gets width.
 * @precision: the precision specifier
 * @size: the size specifier
  * Return: returns number of characters printed.
 */

int print_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * print_num - Write number using bufffer
 * @indx: Index which the number starts on the buffer
 * @buffer: array buffer to handle print
 * @flags: calculates flags active
 * @width: it gets width
 * @prec: the Precision specifier
 * @length: the Number length
 * @padd: Pading character
 * @extra_c: Extra characters
 * Return: returns number of printed chars.
 */

int print_num(int indx, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int k, padd_start = 1;

	if (prec == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0' && width == 0)
		return (0); 
	if (prec == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
		buffer[indx] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--indx] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (k = 1; k < width - length + 1; k++)
			buffer[k] = padd;
		buffer[k] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--indx] = extra_c;
			return (write(1, &buffer[indx], length) + write(1, &buffer[1], k - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--indx] = extra_c;
			return (write(1, &buffer[1], k - 1) + write(1, &buffer[indx], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], k - padd_start) +
				write(1, &buffer[indx], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--indx] = extra_c;
	return (write(1, &buffer[indx], length));
}

/**
 * print_unsgnd - prints an unsigned number
 * @is_negative: the Number indicating if the num is negative
 * @indx: Index which the number starts in the buffer
 * @buffer: Array of characters
 * @flags: the Flags specifiers
 * @width: the Width specifier
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: returns number of written characterss.
 */

int print_unsgnd(int is_negative, int indx,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - indx - 1, k = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--indx] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (k = 0; k < width - length; k++)
			buffer[k] = padd;

		buffer[k] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[indx], length) + write(1, &buffer[0], k));
		}
		else
		{
			return (write(1, &buffer[0], k) + write(1, &buffer[indx], length));
		}
	}

	return (write(1, &buffer[indx], length));
}

/**
 * print_pointer - prints memory address
 * @buffer: Arrays of chararacters
 * @indx: Index which the number starts in the buffer
 * @length: the Length of number
 * @width: the Width specifier
 * @flags: the Flags specifier
 * @padd: the Characters representing the padding
 * @extra_c: the Characters representing extra chars
 * @padd_start: the Index which padding should start
 * Return: returns number of written characters.
 */

int print_pointer(char buffer[], int indx, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int k;

	if (width > length)
	{
		for (k = 3; k < width - length + 3; k++)
			buffer[k] = padd;
		buffer[k] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';
			if (extra_c)
				buffer[--indx] = extra_c;
			return (write(1, &buffer[indx], length) + write(1, &buffer[3], k - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';
			if (extra_c)
				buffer[--indx] = extra_c;
			return (write(1, &buffer[3], k - 3) + write(1, &buffer[indx], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], k - padd_start) +
				write(1, &buffer[indx], length - (1 - padd_start) - 2));
		}
	}
	buffer[--indx] = 'x';
	buffer[--indx] = '0';
	if (extra_c)
		buffer[--indx] = extra_c;
	return (write(1, &buffer[indx], BUFF_SIZE - indx - 1));
}
