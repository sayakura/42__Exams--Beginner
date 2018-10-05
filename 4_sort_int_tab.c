/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

int 	compare(int a, int b)
{
	return (a > b) ? 1 : 0;
}

void  	swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void 	sort_int_tab(int *tab, unsigned int size)
{
	if (size == 0 || size == 1)
		return ;
	unsigned int index = 0;
	while (index < size - 1)
	{
		if (compare(tab[index], tab[index + 1]))
		{
			swap(&tab[index], &tab[index + 1]);
			index = 0;
		}
		else
		    index++;
	}
}