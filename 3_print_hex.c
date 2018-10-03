/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_print_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 22:32:28 by qpeng             #+#    #+#             */
/*   Updated: 2018/10/02 22:39:11 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *g_base = "0123456789abcdef";

void	pc(int c)
{
	write(1, &c, 1);
}

int		atoi(char *str)
{
	int i = 0;
	unsigned int result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (int)(result);
}

void	ph(int num)
{
	if (num >= 16)
		ph(num / 16);
	pc(g_base[num % 16]);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		pc('\n');
		return (0);
	}
	else
	{
		int num = atoi(av[1]);
		ph(num);
		pc('\n');
	}
	return (0);
}
/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/
