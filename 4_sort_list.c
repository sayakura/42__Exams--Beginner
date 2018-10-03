/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 09:47:54 by exam              #+#    #+#             */
/*   Updated: 2018/10/02 10:03:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *head = lst;
	int temp;
	
	if (!head)
		return (NULL);
	while (head && head->next)
	{
		if (cmp(head->data, head->next->data) == 0)
		{
			temp = head->next->data;
			head->next->data = head->data;
			head->data = temp;
			head = lst;
		}
		else
			head = head->next;
	}
	return (lst);
}
