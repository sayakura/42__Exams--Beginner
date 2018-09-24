/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 20:36:26 by exam              #+#    #+#             */
/*   Updated: 2018/08/31 20:50:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *g_base = "0123456789ABCDEF";

char 	convert(int value)
{
	if (value < 0)
		return g_base[-value];
	else
		return g_base[value];
}

char	*ft_itoa_base(int value, int base)
{
	if (base <= 1 || base > 16)
		return (char *)(0);
	int negative = (value < 0) ? 1 : 0;
	int size = 2 + ((base == 10) ? negative : 0);
	char *res;
	int temp = value;
	while ((temp /= base) != 0 )
		size++;
	res = malloc(size * sizeof(char));
	res[--size] = '\0';
	res[--size] = convert(value % base);
	while((value /= base) != 0)
		res[--size] = convert(value % base);
 	if (negative && base == 10)
		res[--size]  = '-';
	return res;
}
