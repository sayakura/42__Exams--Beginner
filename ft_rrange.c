/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 01:31:35 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/14 02:12:47 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int	len = (end - start) < 0 ? ~(end - start) + 1 : (end - start); 
	int *ptr;
	int index = 0;

	if (!(ptr = (int *)malloc(sizeof(int) * len + 1)))
		return (NULL);	
	while (end != start)
		ptr[index++] =  (end > start) ? end-- :end++;
	ptr[index] = start;
	return (ptr);
}
