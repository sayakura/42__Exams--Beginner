/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 03:44:59 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/26 21:16:09 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_hex(char c)
{
	if ((c >> 4) > 9)
		ft_putchar((c >> 4) - 10 + 'a');
	else
		ft_putchar((c >> 4) + '0');
	if ((c & 0xf) > 9)
		ft_putchar((c & 0xf) - 10 + 'a');
	else
		ft_putchar((c & 0xf) + '0');
}

void	print_addr(unsigned int bits_of_int)
{
	print_hex((bits_of_int >> 24) & 0xff);
	print_hex((bits_of_int >> 16) & 0xff);
	print_hex((bits_of_int >> 8) & 0xff);
	print_hex(bits_of_int & 0xff);
	ft_putchar(':');
	ft_putchar(' ');
}

void	print_content(char *addr, unsigned size)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i >= size)
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		else
			print_hex(addr[i]);
		if (i % 2 == 1)
		{
			ft_putchar(' ');
		}
		i++;
	}
}

void	print_text(char *addr, unsigned int size)
{
	int i;

	i = 0;
	while (i < 16 && i < size)
	{
		if (addr[i] >= ' ' && addr[i] <= '~')
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int offset;

	offset = 0;
	while (offset < size)
	{
		print_addr(offset);
		print_content((char*)addr + offset, size - offset);
		print_text((char*)addr + offset, size - offset);
		offset += 16;
		ft_putchar('\n');
	}
	return (addr);
}
