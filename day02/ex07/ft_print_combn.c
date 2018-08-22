/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 23:52:10 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/21 16:22:57 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		is_printable_number(int level, int n)
{
	int max;

	max = 10;
	while (level-- > 0)
		if ((n % 10) < max)
		{
			max = n % 10;
			n /= 10;
		}
		else
			return (0);
	return (1);
}

void	print_number(int level, int n)
{
	if (level > 1)
		print_number(level - 1, n / 10);
	ft_putchar((n % 10) + '0');
}

int		pow10(int n)
{
	if (n == 0)
		return (1);
	else
		return (pow10(n - 1) * 10);
}

void	ft_print_combn(int n)
{
	int limit;
	int counter;
	int first;

	limit = pow10(n);
	counter = -1;
	first = 1;
	while (++counter < limit)
	{
		if (is_printable_number(n, counter))
		{
			if (first)
				first = 0;
			else
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			print_number(n, counter);
		}
	}
}
