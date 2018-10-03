/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_first_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 01:05:39 by qpeng             #+#    #+#             */
/*   Updated: 2018/10/02 01:11:24 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pc(char c)
{
	write(1, &c, 1);
}

int 	is_spc(char c)
{
	return (c == ' ' || c == '\t' 
			|| c == '\n');
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		pc('\n');
		return (0);
	}
	else
	{
		int i = 0;
		if (av[1][i])
		{
			while (is_spc(av[1][i]))
				i++;
			while (av[1][i] && !is_spc(av[1][i]))
				pc(av[1][i++]);
		}
		pc('\n');
	}
	return (0);
}
