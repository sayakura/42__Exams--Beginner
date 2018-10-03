/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_wdmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 22:15:38 by qpeng             #+#    #+#             */
/*   Updated: 2018/10/02 22:31:44 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		int temp = 0, j = 0, pointer = 0;
		char c;
		char stack[256];
		for (int i = 0; av[1][i]; i++)
		{
			c = av[1][i];
			for (j = temp; av[2][j]; j++)
				if (av[2][j] == c)
				{
					temp = j;
					break ;
				}
			if (temp != j)
			{
				write(1, "\n", 1);
				return (0);
			}
			else
				stack[pointer++] = av[2][temp];
		}
		write(1, stack, pointer);
		write(1, "\n", 1);
	}
	return (0);
}
/*------------------------------------------------------------------------------
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "forty two" "qfqfsoudf arzgrsayns tsryegftdgs sjytwdekuooixq " | cat -e
forty two$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
------------------------------------------------------------------------------*/
