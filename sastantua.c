/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 03:52:45 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/26 19:32:15 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print(int length, char sym)
{
	while (length--)
		ft_putchar(sym);
}

int		cal_base(int size)
{
	if (size == 1)
		return (2 * (size + 2) + 1);
	if (size % 2 == 0)
		return (cal_base(size - 1) + (size + 2) + 2 * (size + 2));
	else
		return (cal_base(size - 1) + (size + 1) + 2 * (size + 2));
}

void	is_door(int f_level, int size, int i, int length)
{
	int door_size;

	door_size = size;
	if (size % 2 == 0)
		door_size = size - 1;
	if (f_level < door_size
	&& ((i >= (length / 2) - (door_size / 2)
	&& i <= (length / 2) + (door_size / 2))))
		if (f_level == (door_size / 2)
			&& i == (length / 2) + (door_size / 2) - 1
			&& size > 4)
			print(1, '$');
		else
			print(1, '|');
	else
		print(1, '*');
}

void	print_level(int space, int length, int f_level, int size)
{
	int i;

	i = 0;
	f_level += 2;
	while (f_level--)
	{
		if (space)
			print(space, ' ');
		i = -1;
		while (++i < length)
			if (i == 0)
				print(1, '/');
			else if (i + 1 == length)
				print(1, '\\');
			else
				is_door(f_level, size, i, length);
		length += 2;
		space -= 1;
		print(1, '\n');
	}
}

void	sastantua(int size)
{
	int space;
	int floor_width;
	int current_width;
	int f_level;
	int max_width;

	f_level = 1;
	if (size > 0)
		max_width = cal_base(size);
	while (f_level <= size && size > 0)
	{
		floor_width = cal_base(f_level);
		current_width = floor_width - (f_level + 1) * 2;
		space = (max_width - current_width) / 2;
		if (f_level == size)
			print_level(space, current_width, f_level, size);
		else
			print_level(space, current_width, f_level, 0);
		f_level++;
	}
}
