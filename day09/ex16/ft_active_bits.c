/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 05:27:34 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/29 05:27:53 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				abs(int value)
{
	return (value < 0 ? -value : value);
}

unsigned int	ft_active_bits(int value)
{
	unsigned int	count;
	int				neg;

	count = 0;
	neg = 0;
	if (value < 0)
	{
		neg = 1;
		value++;
	}
	while (value != 0)
	{
		count += abs(value % 2);
		value /= 2;
	}
	if (neg)
		return (32 - count);
	return (count);
}
