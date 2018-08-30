/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 06:44:48 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/28 07:25:49 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int		count_len(int argc, char **argv)
{
	int		index;
	int		total;

	index = 0;
	total = 0;
	while (index < argc)
	{
		total += ft_strlen(argv[index]);
		index++;
	}
	return (total);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*long_ass_str;
	int		length;
	int		index;
	int		jdex;
	int		tdex;

	index = 0;
	tdex = 0;
	length = count_len(argc, argv);
	long_ass_str = malloc(sizeof(char) * length + 1);
	while (index < argc)
	{
		jdex = 0;
		while (jdex < ft_strlen(argv[index]))
		{
			long_ass_str[tdex] = argv[index][jdex];
			jdex++;
			tdex++;
		}
		index++;
	}
	long_ass_str[tdex] = '\0';
	return (long_ass_str);
}
