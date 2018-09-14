/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:51:20 by kpeng             #+#    #+#             */
/*   Updated: 2018/09/05 11:56:54 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_headers.h"

int		min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= c && b <= a)
		return (b);
	else
		return (c);
}

t_list	*ft_create_elem(int data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem != NULL)
	{
		elem->data = data;
		elem->next = NULL;
	}
	return (elem);
}

void	ft_list_push_back(t_list **first_line, int data)
{
	t_list	*elem;

	if (first_line && *first_line)
	{
		elem = *first_line;
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = ft_create_elem(data);
	}
	else
		*first_line = ft_create_elem(data);
}

void	ft_putstr(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
		write(2, &str[index++], 1);
}

int		ft_atoi(char *str, int length)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (i < length)
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i] - '0');
		else
			return (-1);
		i++;
	}
	return (num);
}
