/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 00:51:29 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/14 00:58:25 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' ||
			c == '\f' || c == '\t' || c == '\n' || c == '\v') ?
			1 : 0;
}
int	ft_atoi(const char *str)
{
	int num;
	int index;
	int sign;

	sign = 1;
	index = 0;
	num = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		num = num * 10 + (str[index] - '0');
		index++;
	}
	return (num * sign);
}
