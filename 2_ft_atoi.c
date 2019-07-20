/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int 	ft_isspace(char c)
{
	return (c == ' ' ||
			c == '\n' ||
			c == '\f' ||
			c == '\v' ||
			c == '\r' ||
			c == '\t');
}

int		ft_atoi(const char *str)
{
	unsigned long long	result;
	unsigned int		index;
	char				sign;

	index = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = 0;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		result = result * 10 + (str[index] - '0');
		if (result > 9223372036854775807)
			if (sign)
				return (-1);
			else
				return (0);
		index++;
	}
	return (int)((sign) ? (result) : (-result));
}
/*------------------------------------------------------------------------------
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
------------------------------------------------------------------------------*/
