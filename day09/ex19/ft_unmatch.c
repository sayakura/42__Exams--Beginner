/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 05:28:26 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/29 05:28:30 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unmatch(int *tab, int length)
{
	int	i;
	int	x;
	int	count;

	i = 0;
	while (i < length)
	{
		x = 0;
		count = 0;
		while (x < length)
		{
			if (tab[x] == tab[i])
				count++;
			x++;
		}
		if (count % 2 == 1)
			return (tab[i]);
		i++;
	}
	return (0);
}
