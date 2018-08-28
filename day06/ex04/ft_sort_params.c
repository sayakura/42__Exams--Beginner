/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 04:28:11 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/28 05:47:46 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

int		compare(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str2[i])
		if (str1[i] == str2[i])
			i++;
		else
			break ;
	return (str1[i] - str2[i]);
}

void	sort(char **arr, int length)
{
	int		index;
	int		jdex;
	char	*temp;

	index = 2;
	while (index < length)
	{
		jdex = index;
		temp = arr[index];
		while (jdex > 1 && compare(temp, arr[jdex - 1]) < 0)
		{
			arr[jdex] = arr[jdex - 1];
			jdex--;
		}
		arr[jdex] = temp;
		index++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc != 1)
		sort(argv, argc);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
