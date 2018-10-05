/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

int	    is_power_of_2(unsigned int n)
{
	if (n <= 0)
		return (0);
	return ((n & (n - 1)) == 0);
}
