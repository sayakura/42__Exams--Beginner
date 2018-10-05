/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

#include <stdlib.h>

#define abs(a) (a < 0) ? -a : a
char *g_base = "0123456789ABCDEF";

char	*ft_itoa_base(int value, int base)
{
	int negative = (base == 10 && value < 0) ? 1 : 0;
	int size = (negative) ? 3 : 2;
	int temp = value;
	while (temp /= base)
		size++;
	char *res = malloc(sizeof(char) * size);
	res[--size] = '\0';
	res[--size] = g_base[abs(value % base)]; 
	while (value /= base)
		res[--size] = g_base[abs(value % base)]; 
	if (negative == 1)
		res[--size] = '-';
	return res;
}
/* ***************************************************************************
Assignment name  : ft_itoa_base
Expected files   : ft_itoa_base.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that converts an integer value to a null-terminated string
using the specified base and stores the result in a char array that you must
allocate.

The base is expressed as an integer, from 2 to 16. The characters comprising
the base are the digits from 0 to 9, followed by uppercase letter from A to F.

For example, base 4 would be "0123" and base 16 "0123456789ABCDEF".

If base is 10 and value is negative, the resulting string is preceded with a
minus sign (-). With any other base, value is always considered unsigned.

Your function must be declared as follows:

char	*ft_itoa_base(int value, int base);
 * ***************************************************************************/