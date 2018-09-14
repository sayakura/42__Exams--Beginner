/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:09:38 by kpeng             #+#    #+#             */
/*   Updated: 2018/09/05 12:23:57 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_headers.h"
#include "../includes/ft_utils.h"
#include "../includes/map_utils.h"
#include "../includes/ft_functions.h"

int		ft_read_syms(const char *filename)
{
	int			fd;
	int			i;
	char		*info;
	char		buffer[2];

	buffer[0] = 0;
	i = -1;
	info = malloc(sizeof(char) * 30);
	fd = open(filename, O_RDONLY);
	if (-1 == fd)
		return (-1);
	while ((read(fd, buffer, 1) > 0))
	{
		if (++i > 20)
			return (-1);
		else if (buffer[0] != '\n')
			info[i] = buffer[0];
		else
			break ;
	}
	info[i] = '\0';
	g_map_info = save_info(info);
	g_map_info->fd = fd;
	free(info);
	return (1);
}

int		ft_read_syms_from_input(char **input)
{
	int			i;
	char		*info;

	i = 0;
	info = malloc(sizeof(char) * 30);
	if (!input)
		return (-1);
	while (**input)
	{
		if (i > 20)
			return (-1);
		else if (**input != '\n')
			info[i] = **input;
		else
		{
			(*input)++;
			break ;
		}
		i++;
		(*input)++;
	}
	info[i] = '\0';
	g_map_info = save_info(info);
	free(info);
	return (1);
}

char	*read_from_input(void)
{
	/* for stdin, handle up to 1000 * 1000 */
	char	buffer[1009000];
	int		flag;
	int		total_size;
	char	*str;

	buffer[1] = '\0';
	total_size = 0;
	/* it was * 10000 and I failed the last functional test, 
	I forgot to make it bigger, there is better way to do it
	and the size can be more dynamic, but I ran out of time.*/
	str = malloc(sizeof(char) * 1009000);
	flag = 0;
	while ((flag = read(0, buffer, 1009000)) > 0)
	{
		total_size += flag;
		ft_strcat(str, buffer);
	}
	return (str);
}

int		ft_validate_argv(const char *filename, char *input)
{
	if (input == 0)
	{
		if (ft_read_syms(filename) == -1)
			return (-1);
	}
	else
	{
		if (ft_read_syms_from_input(&input) == -1)
			return (-1);
	}
	if (g_map_info->size < 0)
		return (-1);
	if (g_map_info->full == g_map_info->empty || g_map_info->full ==
		g_map_info->obstacle || g_map_info->empty == g_map_info->obstacle)
		return (-1);
	g_sqr = malloc(sizeof(t_biggest));
	g_sqr->row = 0;
	g_sqr->col = -1;
	g_sqr->d = 0;
	if (map_reader(g_map_info->fd, input) == -1)
		return (-1);
	print_t_map(g_map_info->int_map);
	free_everything();
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*ptr;

	i = 1;
	while (i < argc)
	{
		main_helper(i);
		if (ft_validate_argv(argv[i], 0) == -1)
			ft_putstr("map error\n");
		i++;
	}
	if (i == 1)
	{
		main_helper(i);
		ptr = read_from_input();
		if (ft_validate_argv((const char *)(0), ptr) == -1)
			ft_putstr("map error\n");
	}
	return (0);
}
