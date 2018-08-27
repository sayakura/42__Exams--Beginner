/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 16:25:52 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/26 17:33:31 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*d;
	char			*s;
	unsigned int	siz;
	unsigned int	dlen;

	s = src;
	d = dest;
	siz = size;
	while (siz-- != 0 && *d != '\0')
		d++;
	dlen = d - dest;
	siz = size - dlen;
	if (siz == 0)
		return (dlen + ft_strlen(src));
	while (*s != '\0')
	{
		if (siz != 1)
		{
			*d++ = *s;
			siz--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + s - src);
}
