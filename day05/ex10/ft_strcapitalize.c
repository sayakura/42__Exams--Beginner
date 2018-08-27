/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:53:36 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/24 12:16:56 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_letter(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (2);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		in_word;
	int		*ptr;

	ptr = str;
	in_word = 0;
	while (*str)
	{
		if (is_letter(*str) == 1 && in_word == 0)
		{
			*str -= 32;
			in_word = 1;
		}
		else if (*str >= '0' && *str <= '9')
			in_word = 1;
		else if (is_letter(*str) == 2 && in_word == 1)
			*str += 32;
		else if (is_letter(*str) == 0)
			in_word = 0;
		str++;
	}
	return (ptr);
}
