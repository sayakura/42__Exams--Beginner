/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*--bin search for squart root of a number O(log n)--*/
int 	sqrt_of(int num)
{
	if (num == 0 || num == 1)
		return (num);
	int start = 0, end = num, ans;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (mid <= num / mid)
		{
			start = mid + 1;
			ans = mid;
		}
		else
			end = mid - 1;
	}
	return ans;
}

int		is_prime(int num)
{
	if (num < 2)
		return (0);
	else if (num <= 3 || num % 2 == 0 || num % 3 == 0)
		return (1);
	int i = 3;
	int max = sqrt_of(num);
	while (i < 46340 && i < max)
	{
		while (num % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		printf("\n");
	else
	{
		int i = 1;
		int num = atoi(av[1]);
		if (num == 1) // tbh 1 is not a prime : )
		{
			printf("1\n");
			return (0);
		}
		int aterisk = 0;
		while (i <= num)
		{
			if (num % i == 0 && is_prime(i))
			{
				if (aterisk != 0)
					printf("*");
				aterisk = 1;
				printf("%d", i);
				num /= i;
				continue ;
			}
			i++;
		}
		printf("\n");
	}
	return (0);
}
/*--------------------------------------------------------------------------------
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there's one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
------------------------------------------------------------------------------*/
