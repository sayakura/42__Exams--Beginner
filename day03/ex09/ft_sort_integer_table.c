/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 20:20:25 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/21 21:08:33 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *tab, int i, int j)
{
	int c;

	c = tab[i];
	tab[i] = tab[j];
	tab[j] = c;
}

int		compare(int a, int b)
{
	if (a > b)
		return (1);
	else
		return (0);
}

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size - 1)
		{
			if (compare(tab[i], tab[j]))
				swap(tab, i, j);
			j++;
		}
		i++;
	}
}
