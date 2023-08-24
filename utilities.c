#include "main.h"

/**
 * is_printables - Evaluates if char is printable
 * @m: Char to be evaluated.
 *
 * Return: Return 1 if m is printable, 0 otherwise
 */

int is_printables(char m)
{
	if (m >= 32 && m < 127)
		return (1);

	return (0);
}

/**
 * append_hex_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @k: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return:  Always returns 3
 */

int append_hex_code(char ascii_code, char buffer[], int k)
{
	char map_to[] = "0123456789ABCDEF"

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[k++] = '\\';
	buffer[k++] = 'x';

	buffer[k++] = map_to[ascii_code / 16];
	buffer[k] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_dgt - Verifies if a char is a digit
 * @m: Char to be evaluated
 *
 * Return: Return 1 if m is a digit, 0 otherwise
 */

int is_dgt(char m)
{
	if (m >= '0' && m <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_num - Casts a number into the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Return casted value of num
 */

long int convert_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsg - Casts a number into the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Return casted value of num
 */

long int convert_size_unsg(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
