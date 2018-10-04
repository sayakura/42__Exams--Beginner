/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 01:00:49 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/26 21:40:46 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int 	valid_convert(char c, int base)
{
	char	*char_base = "0123456789abcdef";
	int		index = 0;

	while (index < base)
	{
		if (c == char_base[index])
			return (index);
		else if (index >= 10 && c == (char_base[index] - 32))
			return (index);
		index++;
	}
	return (-1);
}

int			ft_atoi_base(const char *str, int str_base)
{
	unsigned long long	num = 0;
	int					index = 0;
	int					sign = 1;

	if (str_base > 16 || str_base < 2)
		return (0);
	if (str[index] == '-')
	{
		sign = 0;
		index++;
	}
	while (valid_convert(str[index], str_base) != -1)
	{
		num = num * str_base + (valid_convert(str[index], str_base));
		if (result > 9223372036854775807)
			if (sign)
				return (-1);
			else
				return (0);
		index++;
	}
	return (int)((sign) ? (num) : (-num));
}
/* 
the real atoi will return -1 when a the input represents
a number that is greater than max of long long (2 ^ 63 - 1).
*/
