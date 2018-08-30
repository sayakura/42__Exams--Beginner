/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 05:15:29 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/29 05:15:31 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int		i;
	char	*output;

	i = 0;
	while (src[i])
		i++;
	if ((output = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	struct s_stock_par	*st;

	st = malloc(sizeof(t_stock_par) * (ac + 1));
	if (st == NULL)
		return (NULL);
	st[ac].str = 0;
	while (--ac >= 0)
	{
		st[ac].size_param = ft_strlen(av[ac]);
		st[ac].str = av[ac];
		st[ac].copy = ft_strdup(av[ac]);
		st[ac].tab = ft_split_whitespaces(st[ac].str);
		if (st[ac].tab == NULL || st[ac].copy == NULL)
			return (NULL);
	}
	return (st);
}
