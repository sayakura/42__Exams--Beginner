/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:48:20 by kpeng             #+#    #+#             */
/*   Updated: 2018/09/12 22:20:47 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_headers.h"
#include "../includes/ft_utils.h"
#include "../includes/ft_functions.h"

void		print_t_map(int **map)
{
	g_i->index = 0;
	g_i->str = (char *)malloc(sizeof(char) * g_i->str_length);
	g_i->i = -1;
	while (++g_i->i < g_map_info->size)
	{
		g_i->j = -1;
		while (++g_i->j < g_map_info->line_length)
		{
			if (g_i->i > g_sqr->row - g_sqr->d && g_i->i <= g_sqr->row)
				if (g_i->j > g_sqr->col - g_sqr->d && g_i->j <= g_sqr->col)
					g_i->str[g_i->index] = g_map_info->full;
				else
					g_i->str[g_i->index] = (map[g_i->i][g_i->j] > 0) ?\
					g_map_info->empty : g_map_info->obstacle;
			else
				g_i->str[g_i->index] = (map[g_i->i][g_i->j] > 0) ?\
				g_map_info->empty : g_map_info->obstacle;
			g_i->index++;
		}
		g_i->str[g_i->index++] = '\n';
	}
	write(1, g_i->str, g_i->str_length);
	free(g_i->str);
}

t_map_info	*save_info(char *info_arr)
{
	int			len;
	t_map_info	*map_info;

	map_info = (t_map_info *)malloc(sizeof(t_map_info));
	len = 0;
	while (info_arr[len] != 0)
		len++;
	map_info->full = info_arr[len - 1];
	map_info->obstacle = info_arr[len - 2];
	map_info->empty = info_arr[len - 3];
	map_info->size = ft_atoi(info_arr, len - 3);
	return (map_info);
}

int			validate_sym(char c)
{
	return (c == g_map_info->obstacle || c == g_map_info->empty);
}

void		check_biggest_square(int row, int col, int **int_map)
{
	int	d;

	if (col == 0)
		d = 1;
	else
		d = (min(int_map[row][col - 1], int_map[row - 1][col], \
		int_map[row - 1][col - 1])) + 1;
	int_map[row][col] = d;
	if (d >= g_sqr->d)
	{
		if (d > g_sqr->d ||
			(row <= g_sqr->row && col <= g_sqr->col))
		{
			g_sqr->row = row;
			g_sqr->col = col;
		}
		g_sqr->d = d;
	}
}

void		free_everything(void)
{
	int i;

	i = 0;
	while (i < g_map_info->size)
	{
		free(g_map_info->int_map[i]);
		i++;
	}
	free(g_map_info->int_map);
	close(g_map_info->fd);
	free(g_map_info);
	free(g_sqr);
}
