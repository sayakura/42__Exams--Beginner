/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 09:13:29 by exam              #+#    #+#             */
/*   Updated: 2018/10/09 09:30:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	stack[1256];
int		pointer = -1;

void 	pc(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	if (ac != 3)
	{
		pc('\n');
		return (0);
	}
	else
	{
		int j = 0;
		int temp = 0;
		char c = 0;
		for (int i = 0; av[1][i]; i++)
		{
			c = av[1][i];
			if (!av[2][j])
			{
				pc('\n');
                return (0);
			}
			for (j = temp; av[2][j]; j++)
			{
				if (av[2][j] == c)
				{
					stack[++pointer] = av[2][j++];
					temp = j;
					break ;
				}	
			}
			if (j != temp)
			{
				pc('\n');
				return (0);
			}
		}
		write(1, stack, pointer + 1);
		pc('\n');
	}
	return (0);
}
