#include <unistd.h>
#include <stdlib.h>
void	pc(char c)
{
	write(1, &c, 1);
}

void	ps(char *s)
{
	while (*s)
		pc(*s++);
}

void	reverse(char *s, int start, int end)
{
	char temp;
	while (start < end)
	{
		temp = s[start];
		s[start++] = s[end];
		s[end--] = temp;
	}
}

int 	sl(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	rev_wstr(char *str)
{
	int len = sl(str);
	int i = 0;
	char *arr = (char *)malloc(sizeof(char) * len + 1);
	arr[len] = '\0';
	while ((arr[i] = str[i]) != '\0')
		i++;
	/////////////	
	int start = 0;
	int temp = 0;
	while (arr[temp])
	{
		temp++;
		if (arr[temp] == ' ' || arr[temp] == '\0')
		{
			reverse(arr, start, temp - 1);
			start = temp + 1;
		}
	}
	reverse(arr, 0, i - 1);
	ps(arr);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		pc('\n');
		return (0);
	}
	else
	{
		if (av[1][0])
			rev_wstr(av[1]);
		pc('\n');
	}
	return (0);
}