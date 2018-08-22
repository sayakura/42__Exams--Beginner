/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:42:35 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/21 16:12:17 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j <= 99)
	{
		i = j;
		while (i < 99)
		{
			i++;
			ft_putchar(j / 10 + '0');
			ft_putchar(j % 10 + '0');
			ft_putchar(' ');
			ft_putchar(i / 10 + '0');
			ft_putchar(i % 10 + '0');
			if (!(j == 98 && i == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
		j++;
	}
}
