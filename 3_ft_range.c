/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int size = (start < end) ? end - start : start - end;
	int *arr = malloc(sizeof(int) * size + 1);
	int i = 0;
	while (start != end)
		arr[i++] = (start < end) ? start++ : start--;
	arr[i] = end;
	return (arr);
}

/*------------------------------------------------------------------------------
#include <stdio.h>
int 	main(void)
{
	int start = 2147483647, end = 2147483640, i = 0;
	int size = (start < end) ? end - start : start - end;
	int *tab = ft_range(start, end);
	while (i < size + 1)
		printf("%d ", tab[i++]);
	printf("\n");
	return (0);
}
------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
------------------------------------------------------------------------------*/
