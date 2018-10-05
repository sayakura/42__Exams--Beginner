/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/
#include <unistd.h>

void	pc(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	if (ac != 4 || av[2][1] || av[3][1])
	{
		pc('\n');
		return (0);
	}
	int i = 0;
	while (av[1][i])
	{
		if (av[1][i] == av[2][0])
			pc(av[3][0]);
		else
			pc(av[1][i]);
		i++;
	}
	pc('\n');
	return (0);
}
/*------------------------------------------------------------------------------
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "My life for Aizr" "z" "u"
My life for Aiur
$>./search_and_replace "gaetan" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "In foct, stoff crew ore very nice. They like metol." "o" "a" | cat -e
In fact, staff crew are very nice. They like metal.$
------------------------------------------------------------------------------*/
