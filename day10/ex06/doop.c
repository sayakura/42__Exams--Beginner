/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 05:45:25 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/29 05:45:28 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		print(char *str);

void	get_op_and_nbr(char **av, int *nbr1, int *nbr2, char *operator)
{
	*nbr1 = ft_atoi(av[1]);
	*nbr2 = ft_atoi(av[3]);
	*operator = av[2][0];
}

int		print_nbr(int nbr)
{
	ft_putnbr(nbr);
	ft_putchar('\n');
	return (0);
}

int		main(int argc, char **argv)
{
	int		nbr[2];
	char	operator;

	if (argc != 4)
		return (0);
	get_op_and_nbr(argv, &nbr[0], &nbr[1], &operator);
	if (operator == '-')
		return (print_nbr(nbr[0] - nbr[1]));
	if (operator == '+')
		return (print_nbr(nbr[0] + nbr[1]));
	if (operator == '/')
	{
		if (nbr[1] == 0)
			return (print("Stop : division by zero\n"));
		return (print_nbr(nbr[0] / nbr[1]));
	}
	if (operator == '%')
	{
		if (nbr[1] == 0)
			return (print("Stop : modulo by zero\n"));
		return (print_nbr(nbr[0] % nbr[1]));
	}
	return (print_nbr(0));
}
