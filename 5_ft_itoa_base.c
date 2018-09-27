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

char convert(int num)
{
	return (num < 0) ? (g_base[-num]) : (g_base[num]);
}

char	*ft_itoa_base(int value, int base)
{
	if (base < 2 || base > 16)
		return (NULL);
	int negative = (base == 10 && value < 0) ? 1 : 0;
	int size = (negative) ? 3 : 2;
	int temp = value;
	while (temp /= base)
		size++;
	char *res = malloc(sizeof(char) * size);
	res[--size] = '\0';
	res[--size] = convert(value % base);
	while (value /= base)
		res[--size] = convert(value % base);
	if (negative == 1)
		res[--size] = '-';
	return res;
}