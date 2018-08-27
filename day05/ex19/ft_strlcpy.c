/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 04:13:07 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/26 20:33:31 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int char_written;

	char_written = 0;
	if (size > 0)
	{
		while (src[char_written] != 0 && char_written < size - 1)
			*dest++ = src[char_written++];
		*dest = 0;
	}
	while (src[char_written] != 0)
		char_written++;
	return (char_written);
}
