/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 02:18:54 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/14 03:00:29 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_bracket(char c)
{
	if (c == 40  || c == 91  || c == 123)
		return (1);
	else if (c == 41 || c == 93 || c == 125)
		return (2);
	return (0);
}

int	match(char a, char b)
{
	if (a == ')')
		return (b == '(');
	else if (a == '}')
		return (b == '{');
	else if (a == ']')
		return (b == '[');
	return (0);
}

int	main(int ac, char **av)
{
	char stack[1024];
	int top = -1;
	int	i = 1;
	int j = 0;
	int	printed = 0;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		while (i < ac)
		{
			j = 0;
			printed = 0;
			top = -1;
			while (av[i][j])
			{
				if (is_bracket(av[i][j]) == 1)
					stack[++top] = av[i][j];
				else if (is_bracket(av[i][j]) == 2)
					if (!match(av[i][j], stack[top--]))
					{
						write(1, "Error\n", 6);
						printed = 1;
						break ;
					}
				j++;
			}
			if (top != -1 && printed == 0)
				write(1, "Error\n", 6);
			else if (printed == 0)
				write(1, "OK\n", 3);
			i++;		
		}
	}
	return (0);
}
