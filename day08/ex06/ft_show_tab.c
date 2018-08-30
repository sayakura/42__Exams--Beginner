/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 05:16:41 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/29 05:16:44 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar('0' + nb % 10);
}

void	ft_print_words_tables(char **tab)
{
	int x;
	int i;

	x = 0;
	while (tab[x])
	{
		i = 0;
		while (tab[x][i])
		{
			ft_putchar(tab[x][i]);
			i++;
		}
		x++;
		ft_putchar('\n');
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	int x;

	x = 0;
	while (par[x].str != 0)
	{
		ft_putstr(par[x].str);
		ft_putchar('\n');
		ft_putnbr(par[x].size_param);
		ft_putchar('\n');
		ft_print_words_tables(par[x].tab);
		x++;
	}
}
