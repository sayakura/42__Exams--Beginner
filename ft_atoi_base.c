/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 01:00:49 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/14 01:30:36 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_convert(char c, int base)
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

int	ft_atoi_base(const char *str, int str_base)
{
	int		num = 0;
	int		index = 0;
	int		sign = 1;

	if (str_base > 16 || str_base <= 1)
		return (0);
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	while (valid_convert(str[index], str_base) != -1)
	{
		num = num * str_base + (valid_convert(str[index], str_base));
		index++;
	}
	return (num * sign);
}
