/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_print_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:41:43 by qpeng             #+#    #+#             */
/*   Updated: 2018/10/01 18:41:45 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char *g_base = "0123456789abcdef";

void	pc(char c)
{
	write (1, &c, 1);
}

void	pa(unsigned char c)
{
	if (c > 31 && c < 127)
		pc(c);
	else
		pc('.');
}

void	ph(unsigned char c)
{
	pc(g_base[c / 16]);
	pc(g_base[c % 16]);
}

void	pl(unsigned char *tab, size_t beg, size_t max)
{
	size_t	i;
	size_t	end = beg + 16;

	for (i = beg; i < end && i < max; i++)
	{
		ph(tab[i]);
		if (i % 2)	pc(' ');
	}
	for (; i < end; i++)
	{
		pc(' ');
		pc(' ');
		if (i % 2)	pc(' ');
	}
	for (i = beg; i < end && i < max; i++)
		pa(tab[i]);
	pc('\n');
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char *tab;

	tab = (unsigned char *)addr;
	for (size_t c = 0; c < size; c += 16)
		pl(tab, c, size);
}
/*------------------------------------------------------------------------------
#include <stdio.h>

int main()
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
    return 0;
}
------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Assignment name  : print_memory
Expected files   : print_memory.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes (const void *addr, size_t size), and displays the
memory as in the example.

Your function must be declared as follows:

void	print_memory(const void *addr, size_t size);

---------
$> cat main.c
void	print_memory(const void *addr, size_t size);

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
$> gcc -Wall -Wall -Werror main.c print_memory.c && ./a.out | cat -e
0000 0000 1700 0000 9600 0000 ff00 0000 ................$
0c00 0000 1000 0000 1500 0000 2a00 0000 ............*...$
0000 0000 0000 0000                     ........$
------------------------------------------------------------------------------*/