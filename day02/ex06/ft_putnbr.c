/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 23:00:00 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/21 16:18:34 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print_number(int n)
{
	if (n >= 0)
		ft_putchar(n + '0');
	else
		ft_putchar(-n + '0');
}

void	recursive_print_number(int nb)
{
	if ((nb > -10) && (nb < 10))
	{
		print_number(nb % 10);
	}
	else
	{
		recursive_print_number(nb / 10);
		print_number(nb % 10);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		ft_putchar('0');
	else
	{
		if (nb < 0)
			ft_putchar('-');
		recursive_print_number(nb);
	}
}
