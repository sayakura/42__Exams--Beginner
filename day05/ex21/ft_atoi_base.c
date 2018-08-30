/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:58:28 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/27 19:05:45 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_space(char c)
{
	if (c == ' '
	|| c == '\f'
	|| c == '\v'
	|| c == '\n'
	|| c == '\r'
	|| c == '\t')
		return (1);
	return (0);
}

int		check_base(char *base)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (base[size] != 0)
	{
		if (base[size] == '+' || base[size] == '-')
			return (-1);
		i = 0;
		while (base[i] != 0)
			if (base[i] == base[size] && i != size)
				return (-1);
			else
				i++;
		size++;
	}
	if (size < 2)
		return (-1);
	return (size);
}

int		is_valid(char c, char *base, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		get_value(char *arr, int size, char *base, int base_size)
{
	int power;
	int num;
	int result;
	int i;
	int j;

	result = 0;
	num = 0;
	power = size;
	i = 0;
	while (i < size)
	{
		num = is_valid(arr[i], base, base_size);
		j = size - i;
		while (--j)
			num *= base_size;
		result += num;
		power++;
		i++;
	}
	return (result);
}

int		ft_atoi_base(const char *str, char *base)
{
	int		sign;
	int		str_len;
	int		i;
	char	arr[1024];
	int		base_size;

	sign = 1;
	str_len = 0;
	i = 0;
	base_size = check_base(base);
	if (base_size < 0)
		return (0);
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (is_valid(str[i], base, base_size) >= 0)
		arr[str_len++] = str[i++];
	arr[str_len] = '\0';
	return (sign * get_value(arr, str_len, base, base_size));
}
