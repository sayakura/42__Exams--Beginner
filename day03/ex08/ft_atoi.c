/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 17:12:16 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/21 23:14:49 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char c)
{
	if (c == ' '
	|| c == '\f'
	|| c == '\v'
	|| c == '\n'
	|| c == '\t'
	|| c == '\r')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int num;
	int sign;

	sign = 1;
	num = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (unsigned int)(*str++ - '0');
	return (sign * num);
}
