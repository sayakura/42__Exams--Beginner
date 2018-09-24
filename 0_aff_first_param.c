/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 03:07:02 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/14 03:08:07 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		while (*av[1])
		{
			ft_putchar(*av[1]);
			(av[1])++;
		}
		ft_putchar('\n');
	}
	return (0);
}
