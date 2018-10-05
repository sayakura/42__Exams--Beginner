/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

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
/* ***************************************************************************
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
l'indifference de celui precede mepris du temps le$
$> ./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "il contempla le mont" | cat -e
mont le contempla il$
$> ./rev_wstr | cat -e
$
$>
 * ***************************************************************************/