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

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		while (*av[ac - 1])
		{
			ft_putchar(*av[ac - 1]);
			(av[ac - 1])++;
		}
		ft_putchar('\n');
	}
	return (0);
}
