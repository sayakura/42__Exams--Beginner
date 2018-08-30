/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 05:45:50 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/29 05:45:53 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int overflow;

	overflow = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			nb = 2147483647;
			overflow = 1;
		}
		else
			nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0' + overflow);
}

int		ft_atoi(char *str)
{
	int pos;
	int i;
	int result;

	i = 0;
	result = 0;
	pos = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f' || \
			str[i] == '\t' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			pos = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * pos);
}

int		print(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (0);
}
