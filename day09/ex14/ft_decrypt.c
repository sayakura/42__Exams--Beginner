/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 05:26:27 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/29 05:26:29 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_perso.h"
#include <stdlib.h>

int		ft_atoi_(char *str, int *index)
{
	int result;
	int i;
	int mult;

	i = 0;
	result = 0;
	mult = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' \
		|| str[i] == '\n' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	*index += i - 1;
	return (result * mult);
}

char	*ft_strdup_(char *src, int *index)
{
	int		i;
	char	*output;

	i = 0;
	while (src[i] && src[i] != ';')
		i++;
	if ((output = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != ';')
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	*index += i;
	return (output);
}

int		count_elements(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = str[0] != 0;
	while (str[i])
	{
		if (str[i] == ';')
			count++;
		i++;
	}
	return (count);
}

t_perso	**ft_decrypt(char *str)
{
	t_perso **perso;
	int		i;
	int		x;
	int		count;

	count = count_elements(str);
	perso = malloc(sizeof(t_perso*) * (count + 1));
	if (perso == NULL)
		return (NULL);
	i = 0;
	x = 0;
	perso[0] = malloc(sizeof(t_perso));
	while (str[i])
	{
		if (str[i] == ';')
			perso[++x] = malloc(sizeof(t_perso));
		else if (str[i] == '|')
			perso[x]->name = ft_strdup_(str + i + 1, &i);
		else
			perso[x]->age = ft_atoi_(str + i, &i);
		i++;
	}
	perso[count] = 0;
	return (perso);
}
