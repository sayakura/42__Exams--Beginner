/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 05:22:41 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/29 05:22:43 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_destroy(char ***factory)
{
	int i;
	int x;

	if (factory == 0)
		return ;
	i = 0;
	while (factory[i] != 0)
	{
		x = 0;
		while (factory[i][x] != 0)
		{
			free(factory[i][x]);
			x++;
		}
		free(factory[i]);
		i++;
	}
	free(factory);
}
