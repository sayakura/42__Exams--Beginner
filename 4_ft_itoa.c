/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 23:45:40 by qpeng             #+#    #+#             */
/*   Updated: 2018/10/01 23:55:22 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int	neg = (nbr < 0) ? 1 : 0;
	int size = (neg) ? 3 : 2;
	int temp = nbr;
	char *base = "0123456789";
	char *ptr;

	while (temp /= 10)
		size++;
	ptr = (char *)malloc(size);
	ptr[--size] = '\0';
	ptr[--size] = (nbr < 0) ? base[-(nbr % 10)] : base[nbr % 10];
	while (nbr /= 10)
		ptr[--size] = (nbr < 0) ? base[-(nbr % 10)] : base[nbr % 10];
	if (neg)
		ptr[--size] = '-';
	return (ptr);
}
/*------------------------------------------------------------------------------
#include <stdio.h>
int 	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(1));
	return (0);
}
------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
------------------------------------------------------------------------------*/
