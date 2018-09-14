/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 19:50:05 by exam              #+#    #+#             */
/*   Updated: 2018/08/31 20:03:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int compare(int a, int b)
{
	if (a > b)
		return 1;
	else 
		return 0;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void sort_int_tab(int *tab, unsigned int size)
{
	if (size == 0 || size == 1)
		return ;
	unsigned int index = 0;
	unsigned int j = 0;
	while (index < size)
	{
		j = index;
		while (j < size)
		{
			if (compare(tab[index], tab[j]))
				swap(&tab[index], &tab[j]);
			j++;
		}
		index++;
	}
}
