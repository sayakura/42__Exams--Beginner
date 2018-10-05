/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1 ,&c, 1);
}


void 	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
	else
		ft_putchar((nb % 10) + 48);
}


int	main(int argc, char **argv)
{
	argv--;
	int args = argc - 1;
	ft_putnbr(args);
	write(1, "\n", 1);
	return (0);
}
