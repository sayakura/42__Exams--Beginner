/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 22:27:15 by kpeng             #+#    #+#             */
/*   Updated: 2018/09/12 20:53:58 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_headers.h"
#include "../includes/ft_utils.h"
#include "../includes/map_utils.h"
#include "../includes/ft_functions.h"

#include <stdio.h>

void	ft_strcat(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	copy_and_verify(char *dest, char *src)
{
	int expected_size;
	int index;

	index = 0;
	expected_size = (g_map_info->size - 1) * (g_map_info->line_length) + \
	(g_map_info->size - 1);
	src += g_map_info->line_length + 1;
	while ((dest[index] = src[index]) != '\0')
		index++;
	if (expected_size != (index))
		g_i->legit = 0;
}

int		map_helper(t_list *first_line, char *buffer)
{
	int		**int_map;

	if (g_map_info->line_length == 0)
		return (-1);
	if (!(int_map = malloc(sizeof(int *) * g_map_info->size)))
		return (-1);
	if (!(int_map[0] = malloc(sizeof(int) * (g_map_info->line_length))))
		return (-1);
	convert_map_first_line(first_line, int_map);
	if (convert_map_the_rest(buffer, int_map) == -1)
		return (-1);
	g_i->str_length = g_map_info->size * g_map_info->line_length +\
	g_map_info->size;
	g_map_info->int_map = int_map;
	return (1);
}

void	main_helper(int i)
{
	if (i != 1)
		write(1, "\n", 1);
	g_i = (t_index *)malloc(sizeof(t_index));
	g_i->id = 0;
	g_i->r = 1;
	g_i->legit = 1;
	g_i->c = 0;
	g_i->j = 0;
}
