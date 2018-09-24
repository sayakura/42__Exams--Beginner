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
	int	len = (end >= start) ? end - start + 1 : start - end + 1; 
	int	*ptr;

	if (!(ptr = (int *)malloc(sizeof(int) * len)))
		return (NULL);	
	while (len--)
		ptr[len] =  (end >= start) ? start++ : start--;
	return (ptr);
}
