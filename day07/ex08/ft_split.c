/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:38:18 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/29 03:22:24 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_separator(char c, char *charset)
{
	int		index;

	index = 0;
	while (charset[index] != '\0')
		if (c == charset[index++])
			return (1);
	return (0);
}

int		count_word(char *str, char *charset)
{
	int		count;
	int		index;
	int		state;
	int		word;
	int		in_sep;

	index = 0;
	count = 0;
	state = 0;
	while (str[index] != '\0')
	{
		if (!is_separator(str[index++]))
			in_sep = 1;
		else
		{

		}
	}
}

char 	**ft_split(char *str, char *charset)
{
	if (*charset == '\0')
		return (char **)(0);
}
