/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 05:58:01 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/28 06:05:57 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while ((dest[i] = src[i]) != '\0')
		i++;
	return (dest);
}

char	*ft_strdup(char *src)
{
	char			*ptr;
	unsigned int	len;

	len = ft_strlen(src) + 1;
	if (!(ptr = malloc(len)))
		return (NULL);
	return (ft_strcpy(ptr, src));
}
