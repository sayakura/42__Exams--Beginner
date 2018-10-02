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
	int	len = 0;
	while (str[len])
		len++;
	return (len);
}

char    *ft_strrev(char *str)
{
	int	end = 0;
	int start = 0;
	char temp;

	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
}