/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 05:23:18 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/29 05:23:26 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	static int	i;

	if (base == 1)
		return (i == 0 ? 1 : i);
	i++;
	if (base & 1)
		return (ft_collatz_conjecture(base * 3 + 1));
	return (ft_collatz_conjecture(base / 2));
}
