/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 00:59:39 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/26 21:51:42 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *a;
	char *b;

	b = to_find;
	if (*b == 0)
		return (str);
	while (*str)
	{
		if (*str != *b)
		{
			str++;
			continue;
		}
		a = str;
		while (1)
		{
			if (*b == 0)
				return (str);
			if (*a++ != *b++)
				break ;
		}
		b = to_find;
		str++;
	}
	return (char *)(0);
}
