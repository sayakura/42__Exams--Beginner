/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:18:05 by exam              #+#    #+#             */
/*   Updated: 2018/09/21 10:20:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*head = begin_list;

	while (head)
	{
		(*f)(head->data);
		head = head->next;
	}
}