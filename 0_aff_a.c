/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

#include <unistd.h>

void	pc(char c )
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		pc('a');
		pc('\n');
		return (0);	
	}
	else
	{
		while (*av[1])
		{
			if (*av[1] == 'a')
			{
				pc('a');
				pc('\n');
				return (0);
			}
			av[1]++;
		}
		pc('\n');
	}
	return (0);
}
/* ***************************************************************************
Assignment name  : aff_a
Expected files   : aff_a.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the first 'a' character it
encounters in it, followed by a newline. If there are no 'a' characters in the
string, the program just writes a newline. If the number of parameters is not
1, the program displays 'a' followed by a newline.

Example:

$> ./aff_a "abc" | cat -e
a$
$> ./aff_a "dubO a POIL" | cat -e
a$
$> ./aff_a "zz sent le poney" | cat -e
$
$> ./aff_a | cat -e
a$
 * ***************************************************************************/