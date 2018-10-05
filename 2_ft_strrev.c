/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

int		ft_strlen(char *str)
{
	int	len = 0;
	while (str[len])
		len++;
	return (len);
}

char    *ft_strrev(char *str)
{
	int	end = 0;
	int start = 0;
	char temp;

	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
}