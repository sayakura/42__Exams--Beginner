/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_space(char c)
{
	return (c == ' ' || c =='\t');
}

int 	main(int ac, char **av)
{
	int index;
	
	index = 0;
	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		while (av[1][index] != '\0')
		{
			while (is_space(av[1][index]))
				index++;
			while (av[1][index] && !is_space(av[1][index]))
				ft_putchar(av[1][index++]);
			while (is_space(av[1][index]))
				index++;
			if (av[1][index] && av[1][++index])
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	return (0);
}
