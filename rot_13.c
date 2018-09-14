/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 03:13:32 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/14 03:32:40 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pc(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int index;
	char let;

	index = 0;
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		while (av[1][index])
		{
			let = av[1][index];
			if (let >= 'a' && let <= 'z')
				(let - 13 < 'a') ? pc('z' - ('a' - (let - 13)) + 1) : pc(let - 13);
			else if (let >= 'A' && let <= 'Z')
				(let - 13 < 'A') ? pc('Z' - ('A' - (let - 13)) + 1) : pc(let - 13);
			else
				pc(let);
			index++;
		}
		pc('\n');
	}
	return (0);
}
