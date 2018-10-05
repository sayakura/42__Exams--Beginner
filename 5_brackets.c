/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

#include <unistd.h>

int is_bracket(char c)
{
	if (c == 40  || c == 91  || c == 123)
		return (1);
	else if (c == 41 || c == 93 || c == 125)
		return (2);
	return (0);
}

int	match(char a, char b)
{
	if (a == ')')
		return (b == '(');
	else if (a == '}')
		return (b == '{');
	else if (a == ']')
		return (b == '[');
	return (0);
}

int	main(int ac, char **av)
{
	char stack[1024];
	int top = -1;
	int	i = 1;
	int j = 0;
	int	printed = 0;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		while (i < ac)
		{
			j = 0;
			printed = 0;
			top = -1;
			while (av[i][j])
			{
				if (is_bracket(av[i][j]) == 1)
					stack[++top] = av[i][j];
				else if (is_bracket(av[i][j]) == 2)
					if (!match(av[i][j], stack[top--]))
					{
						write(1, "Error\n", 6);
						printed = 1;
						break ;
					}
				j++;
			}
			if (top != -1 && printed == 0)
				write(1, "Error\n", 6);
			else if (printed == 0)
				write(1, "OK\n", 3);
			i++;		
		}
	}
	return (0);
}
/* ***************************************************************************
Assignment name  : brackets 
Expected files   : *.c *.h
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes an undefined number of strings in arguments. For each
argument, the program prints on the standard output "OK" followed by a newline 
if the expression is correctly bracketed, otherwise it prints "Error" followed by
a newline.

Symbols considered as 'brackets' are brackets '(' and ')', square brackets '[' 
and ']'and braces '{' and '}'. Every other symbols are simply ignored.

An opening bracket must always be closed by the good closing bracket in the 
correct order. A string which not contains any bracket is considered as a 
correctly bracketed string.

If there is no arguments, the program must print only a newline.

Examples :

$> ./brackets '(johndoe)' | cat -e
OK$
$> ./brackets '([)]' | cat -e
Error$
$> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e
OK$
OK$
$> ./brackets | cat -e
$
$>
 * ***************************************************************************/