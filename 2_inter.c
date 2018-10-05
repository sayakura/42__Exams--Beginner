/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

#include <unistd.h>

char ht[127];
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
		int i = 0;
		while (av[2][i])
		{
			ht[(int)av[2][i]] = 1;
			i++;
		}
		i = 0;
		while (av[1][i])
		{
			if (ht[(int)av[1][i]])
				pc(av[1][i]);
			ht[(int)av[1][i]] = 0;
			i++;
		}
		pc('\n');
	}
	return (0);
}
/*----------------------------------------------------------------    --------------
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
----------------------------------------------------------------    --------------*/
