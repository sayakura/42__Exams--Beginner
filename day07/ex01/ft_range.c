/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 06:07:42 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/28 06:34:52 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		size;
	int		*ptr;

	size = max - min;
	if (size > 0)
	{
		ptr = malloc(sizeof(int) * size);
		if (!(ptr))
			return (int *)(0);
	}
	else
		return (int *)(0);
	while (max >= min)
	{
		ptr[max - min - 1] = max - 1;
		max--;
	}
	return (ptr);
}
