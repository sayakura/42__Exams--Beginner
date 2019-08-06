/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

#include <unistd.h>

void	ft_print_numbers(void)
{
	write(1, "0123456789",10);
}

void	ft_print_numbers(void)
{
	int	num;
	
	num = '0';
	while (num <= '9') 
	{
		write(1, &num,1);
		num++;
    	}
	num = '\n';
	write(1, &num, 1);
}
/*-------------------------------------------------------------------------------
Assignment name  : ft_print_numbers
Expected files   : ft_print_numbers.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that displays all digits in ascending order.

Your function must be declared as follows:

void	ft_print_numbers(void);

--------------------------------------------------------------------------------*/
