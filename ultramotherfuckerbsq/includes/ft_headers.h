/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_headers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:45:46 by kpeng             #+#    #+#             */
/*   Updated: 2018/09/12 22:19:36 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADERS_H
# define FT_HEADERS_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_list
{
	int				data;
	struct s_list	*next;
}				t_list;

typedef struct	s_map_info
{
	int			size;
	int			line_length;
	char		empty;
	char		obstacle;
	char		full;
	int			fd;
	t_list		first_line;
	int			**int_map;
}				t_map_info;

typedef	struct	s_biggest
{
	int			row;
	int			col;
	int			d;
}				t_biggest;

typedef	struct	s_index
{
	int			i;
	int			j;
	int			r;
	int			c;
	int			index;
	int			id;
	char		*str;
	int			str_length;
	int			legit;
}				t_index;

void			main_helper(int i);

t_biggest		*g_sqr;

t_map_info		*g_map_info;

t_index			*g_i;

#endif
