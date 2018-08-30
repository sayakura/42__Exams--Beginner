/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 03:18:52 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/28 04:11:03 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const char	*g_hexbase = "0123456789abcdef";

static const char	*g_hex_upp = "0123456789ABCDEF";

void	ft_putchar(char c);

int		ft_putnbrhex(unsigned long long nb, unsigned int len, int maj)
{
	char	nb_act;
	int		size;

	nb_act = nb % 16;
	size = 1;
	if (nb >= 16)
		size += ft_putnbrhex(nb / 16, len > 0 ? len - 1 : 0, maj);
	else if (len > 0)
	{
		size += len - 1;
		while (--len > 0)
			ft_putchar('0');
	}
	if (maj)
		ft_putchar(g_hex_upp[(int)nb_act]);
	else
		ft_putchar(g_hexbase[(int)nb_act]);
	return (size);
}

void	ft_fill(int count, int space)
{
	while (count < 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (space && count % space == space - 1)
			ft_putchar(' ');
		++count;
	}
}

void	ft_putnstr(char *str, unsigned int len, int hex, int space)
{
	unsigned int	i;

	i = 0;
	while (len > i)
	{
		if (hex)
		{
			ft_putchar(g_hexbase[(int)((unsigned char)str[i] / 16)]);
			ft_putchar(g_hexbase[(int)((unsigned char)str[i] % 16)]);
		}
		else if (str[i] < 127 && str[i] >= 31)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		if (space && (int)i % space == space - 1)
			ft_putchar(' ');
		++i;
	}
	if (hex)
		ft_fill(i, space);
}

void	ft_putline(char *addr, unsigned int offset, unsigned int size)
{
	ft_putnbrhex(offset, 8, 0);
	ft_putchar(':');
	ft_putchar(' ');
	ft_putnstr(addr + offset, size, 1, 2);
	ft_putchar(' ');
	ft_putnstr(addr + offset, size, 0, 0);
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		count;

	count = 0;
	while (size - 16 > count && size - 16 > 0)
	{
		ft_putline(addr, count, 16);
		count += 16;
	}
	if (size - count > 0)
		ft_putline(addr, count, size - count);
	return (addr);
}
