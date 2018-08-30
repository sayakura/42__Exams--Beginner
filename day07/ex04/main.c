/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 08:03:01 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/28 08:09:22 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char **ft_split_whitespaces(char *str);

int ft_count_word(char *str);

#include <stdio.h>

int		main(void)
{
	char 	**arr;
	char 	*str = "apple banan asd , i dontknow";
	int		index;
	int		size;

	index = 0;
	size = ft_count_word(str);
	arr = ft_split_whitespaces(str);
	while (index < size)
	{
		printf("Index: %d, \tword :%s\n", index, arr[index]);
		index++;
	}
	return (0);
}
