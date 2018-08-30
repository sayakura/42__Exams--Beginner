/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:47:52 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/28 15:04:24 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_words_tables(char **tab);

char 	**ft_split_whitespaces(char *str);

int		main(void)
{
	char 	**arr;
	char	*str;

	str = " apple banana pineapple 12 34 ";
	arr = ft_split_whitespaces(str);
	ft_print_words_tables(arr);
	return (0);
}
