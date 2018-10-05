/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

int		max(int* tab, unsigned int len)
{
	if (!tab)
		return (0);
	int max = tab[0];
	for (unsigned int i = 0; i < len; i++)
	{
		if (tab[i] > max)
			max = tab[i];
	}
	return (max);
}

/*------------------------------------------------------------------
#include <stdio.h>
int main()
{
	int tab[] = {34};
	
	printf("%d\n", max(tab, 1));
	return (0);
}
*/
/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/
