/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:16:28 by exam              #+#    #+#             */
/*   Updated: 2018/09/21 09:27:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		ft_strlen(char *str)
{
	int 	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char    *ft_strrev(char *str)
{
	int	len = 0;
	
	len = ft_strlen(str);
	if (len == 0 || len == 1)
	   return (str);
	int index = 0;
	char temp;
	while (index < len / 2)	
	{
		temp = str[index];
		str[index] = str[len - (index + 1)];
		str[len - (index + 1)] = temp;
		index++;
	}
	return (str);
}
