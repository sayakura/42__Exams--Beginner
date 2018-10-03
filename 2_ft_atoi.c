/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 00:51:29 by qpeng             #+#    #+#             */
/*   Updated: 2018/10/02 01:42:44 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline int	ft_isspace(char c)
{
	return (c == ' ' ||
			c == '\t' ||
			c == '\n' ||
			c == '\f' ||
			c == '\v' ||
			c == '\r' ||
			c == '\t');
}

int					ft_atoi(const char *str)
{
	unsigned long long	result;
	unsigned int		index;
	char				sign;

	index = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = 0;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		result = result * 10 + (str[index] - '0');
		if (result > 9223372036854775807)
			return (-1);
		index++;
	}
	return (int)((sign) ? (result) : (-result));
}
/*------------------------------------------------------------------------------
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
------------------------------------------------------------------------------*/
