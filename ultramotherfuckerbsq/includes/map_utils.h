/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:53:24 by kpeng             #+#    #+#             */
/*   Updated: 2018/09/05 21:53:26 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

void		print_t_map(int **map);
t_map_info	*save_info(char *info_arr);
int			map_reader(int fd, char *input);
void		check_biggest_square(int row, int col, int **int_map);
int			convert_map_the_rest(char *buffer, int **int_map);
void		convert_map_first_line(t_list *first_line, int **int_map);
int			validate_sym(char c);
void		free_everything(void);

#endif
