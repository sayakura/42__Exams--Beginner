/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 18:22:55 by exam              #+#    #+#             */
/*   Updated: 2018/08/31 18:37:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int 	is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
 	else if (c >= 'A' && c<= 'Z')
		return 2;
	return 0;
}

int main(int argc, char **argv)
{
	char temp;
	
	if (argc == 2)
	{
		while (*argv[1])
		{
			if (is_alpha(*argv[1]) == 1)
			{
				temp = 'z' - (*argv[1] - 'a');
				ft_putchar(temp);		
			}
			else if (is_alpha(*argv[1]) == 2)
			{
				temp = 'Z' - (*argv[1] - 'A');
				ft_putchar(temp);
			}
			else
			{
				ft_putchar(*argv[1]);
			}
			argv[1]++;
		}
		write(1, "\n", 1);
	}else
	{
		write(1, "\n", 1);
	}
	return 0;
}
