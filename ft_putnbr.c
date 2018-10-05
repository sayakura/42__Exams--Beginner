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

void	ft_putnbr(int n)
{
	int		temp;
	int		n_size;

	n_size = 1;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n = 147483648;
		}
		else
			n = ~(n) + 1;
	}
	temp = n;
	while ((temp /= 10))
		n_size = (n_size << 4) - (n_size << 2) - (n_size << 1);
	while (n_size > 0)
	{
		ft_putchar(n / n_size + '0');
		n %= n_size;
		n_size /= 10;
	}
}
