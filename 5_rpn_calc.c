/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#define SIZE 100

int		stack[SIZE];
int		pointer = -1;

void	push(int c)
{
	stack[++pointer] = c;
}

int		pop()
{
	return (stack[pointer--]);
}

int		top()
{
	return (stack[pointer]);
}

int 	is_emp()
{
	return (pointer == -1);
}

int		is_spc(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int 	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int		is_sym(char c)
{
	return (c == '+' || c == '*' || c == '/' ||
			c == '%' || c == '-');
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\n");
		return (0);
	}
	char c;
	int i = 0, num1, num2;
	while (av[1][i])
	{
		if (av[1][i] && !is_sym(av[1][i]))
		{
			while (av[1][i] && is_spc(av[1][i]))
				i++;
			if (is_num(av[1][i]))
				push(atoi(&av[1][i]));
			while (av[1][i] && is_num(av[1][i]))
				i++;
			i++;
		}
		else
		{
			c = av[1][i];
			if (!is_emp())
				num1 = pop();
			else
				break ;
			if (!is_emp())
				num2 = pop();
			else
				break ;
			if (c == '+')
				push(num1 + num2);
			else if (c == '-')
				push(num2 - num1);
			else if (c == '*')
				push(num1 * num2);
			else if (c == '/' && num1 != 0)
				push(num2 / num1);
			else if (c == '%' && num1 != 0)
				push(num2 % num1);
			i++;
			while (av[1][i] && is_spc(av[1][i]))
				 i++;
		}
	}
	num1 = pop();
	if (pointer != -1)
		printf("Error\n");
	else
		printf("%d\n", num1);
	return (0);
}
/*------------------------------------------------------------------------------
Assignment name  : rpn_calc
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string which contains an equation written in
Reverse Polish notation (RPN) as its first argument, evaluates the equation, and
prints the result on the standard output followed by a newline.

Reverse Polish Notation is a mathematical notation in which every operator
follows all of its operands. In RPN, every operator encountered evaluates the
previous 2 operands, and the result of this operation then becomes the first of
the two operands for the subsequent operator. Operands and operators must be
spaced by at least one space.

You must implement the following operators : "+", "-", "*", "/", and "%".

If the string isn't valid or there isn't exactly one argument, you must print
"Error" on the standard output followed by a newline.

All the given operands must fit in a "int".

Examples of formulas converted in RPN:

3 + 4                   >>    3 4 +
((1 * 2) * 3) - 4       >>    1 2 * 3 * 4 -  ou  3 1 2 * * 4 -
50 * (5 - (10 / 9))     >>    5 10 9 / - 50 *

Here's how to evaluate a formula in RPN:

1 2 * 3 * 4 -
2 3 * 4 -
6 4 -
2

Or:

3 1 2 * * 4 -
3 2 * 4 -
6 4 -
2

Examples:

$> ./rpn_calc "1 2 * 3 * 4 +" | cat -e
10$
$> ./rpn_calc "1 2 3 4 +" | cat -e
Error$
$> ./rpn_calc |cat -e
Error$

-------------------------------------------------------------------------------*/
