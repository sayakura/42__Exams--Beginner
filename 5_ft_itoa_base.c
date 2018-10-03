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

#define abs(a) (a < 0) ? -a : a
char *g_base = "0123456789ABCDEF";

char	*ft_itoa_base(int value, int base)
{
	int negative = (base == 10 && value < 0) ? 1 : 0;
	int size = (negative) ? 3 : 2;
	int temp = value;
	while (temp /= base)
		size++;
	char *res = malloc(sizeof(char) * size);
	res[--size] = '\0';
	res[--size] = g_base[abs(value % base)]; 
	while (value /= base)
		res[--size] = g_base[abs(value % base)]; 
	if (negative == 1)
		res[--size] = '-';
	return res;
}