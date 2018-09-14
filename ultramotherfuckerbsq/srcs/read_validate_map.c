/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_validate_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 22:27:03 by kpeng             #+#    #+#             */
/*   Updated: 2018/09/12 05:11:26 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_headers.h"
#include "../includes/ft_utils.h"
#include "../includes/map_utils.h"
#include "../includes/ft_functions.h"
#include <stdio.h>

void	convert_map_first_line(t_list *first_line, int **int_map)
{
	int		col;

	col = 0;
	while (col < g_map_info->line_length)
	{
		if (g_sqr->col < 0 && first_line->data == 1)
		{
			g_sqr->col = col;
			g_sqr->d = 1;
		}
		int_map[0][col] = first_line->data;
		col++;
		if (col != g_map_info->line_length)
			first_line = first_line->next;
		else
			break ;
	}
}

int		convert_map_the_rest(char *b, int **int_map)
{
	while (g_i->r < g_map_info->size)
	{
		g_i->c = 0;
		int_map[g_i->r] = malloc(sizeof(int) * (g_map_info->line_length));
		while (b[g_i->id] != '\n')
		{
			if (!validate_sym(b[g_i->id]) || !b[g_i->id])
				return (-1);
			if (b[g_i->id] == g_map_info->empty)
				check_biggest_square(g_i->r, g_i->c, int_map);
			else
				int_map[g_i->r][g_i->c] = \
			(b[g_i->id] == g_map_info->empty) ? 1 : 0;
			g_i->c++;
			g_i->id++;
		}
		if (b[g_i->id] == '\n' && (g_i->c == g_map_info->line_length))
			g_i->id++;
		else if (b[g_i->id] == '\0')
			break ;
		else
			return (-1);
		g_i->r++;
	}
	return (1);
}

t_list	*ft_read_first_line(void)
{
	int		len;
	t_list	*first_line;
	char	buffer[2];

	len = 0;
	first_line = 0;
	while (read(g_map_info->fd, buffer, 1) > 0)
	{
		if (buffer[0] == '\n')
			break ;
		if (!validate_sym(buffer[0]))
			return (t_list *)(0);
		else if (first_line == 0)
			first_line = ft_create_elem(\
			(buffer[0] == g_map_info->obstacle) ? 0 : 1);
		else
			ft_list_push_back(&first_line,\
			(buffer[0] == g_map_info->obstacle) ? 0 : 1);
		len++;
	}
	g_map_info->line_length = len;
	return (first_line);
}

t_list	*ft_read_first_line_from_input(char *input)
{
	int		len;
	t_list	*first_line;

	len = 0;
	first_line = 0;
	while (input[len])
	{
		if (input[len] == '\n')
			break ;
		if (!validate_sym(input[len]))
			return (t_list *)(0);
		else if (first_line == 0)
			first_line = ft_create_elem(\
			(input[len] == g_map_info->obstacle) ? 0 : 1);
		else
			ft_list_push_back(\
			&first_line, (input[len] == g_map_info->obstacle) ? 0 : 1);
		len++;
	}
	g_map_info->line_length = len;
	return (first_line);
}

int		map_reader(int fd, char *input)
{
	char	*buffer;
	int		expected_size;
	t_list	*first_line;

	if (input == 0)
	{
		if (!(first_line = ft_read_first_line()))
			return (-1);
	}
	else if (!(first_line = ft_read_first_line_from_input(input)))
		return (-1);
	expected_size = (g_map_info->size - 1) * (g_map_info->line_length) + \
	(g_map_info->size - 1);
	buffer = malloc(sizeof(char) * expected_size);
	if (input == 0)
	{
		if (expected_size != read(fd, buffer, expected_size + 1))
			return (-1);
	}
	else
		copy_and_verify(buffer, input);
	if (g_i->legit != 1 || map_helper(first_line, buffer) == -1)
		return (-1);
	free(buffer);
	return (1);
}
