/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:06:44 by exam              #+#    #+#             */
/*   Updated: 2018/09/21 10:15:19 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("\n");
		return (0);
	}
	else 
	{
		int num1 = atoi(av[1]);
		int num2 = atoi(av[2]);
		int small = (num1 < num2) ? num1 : num2;
		if (num1 == num2)
		{
			printf("%d\n", num1);
			return (0);
		}
		if (small == 0)
		{
			printf("%d\n", 0);
			return (0);
		}
		while (small != 0)
		{
			if (num1 % small == 0 && num2 % small == 0)
			{
				printf("%d\n",small);
				return (0);
			}
			small--;
		}
	}
	return (0);
}
