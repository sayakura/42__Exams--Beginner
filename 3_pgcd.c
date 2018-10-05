/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	pc(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		pc('\n');
		return (0);
	}
	else
	{
		int a = atoi(av[1]);
		int b = atoi(av[2]);
		if (a == 0 || b == 0)
		{
			printf("0\n");
			return (0);
		}
		int small, big, temp;
		if (a < b)
		{
			small = a;
			big = b;
		}
		else
		{
			small = b;
			big = a;
		}
		temp = small;
		while (temp != 0)
		{
			if (big % temp == 0 && (small % temp == 0))
			{
				printf("%d\n", temp);
				break ;
			}
			temp--;
		}
	}
	return (0);
}