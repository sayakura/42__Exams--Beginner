/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:12:01 by exam              #+#    #+#             */
/*   Updated: 2018/09/11 11:34:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_mate(int len, char **board)
{
	int kx = 0;
	int ky = 0;
	int row = 0;
	int col = 0;

	while (row < len)
	{
		col = 0;
		while (col < len)
		{
			if (board[row][col] == 'K')
			{
				kx = row;
				ky = col;
				break ;
			}
			col++;
		}
		row++;
	}
	row = 0;
	col = 0;
	if (kx + 1 != len && ky + 1 != len && ky -1 != -1)
	{
		if (board[kx + 1][ky + 1] == 'P' || board[kx + 1][ky - 1] == 'P')
			return (1);
	}
	row = kx;
	col = ky;

	while (--row != -1 && --col != -1)
	{
		if (board[row][col] == 'P' || board[row][col] == 'R')
			break ;
		if (board[row][col] == 'B' || board[row][col] == 'Q')
			return (1);
	}
	row = kx;
	col = ky;
    while (--row != -1)
    {
        if (board[row][col] == 'P' || board[row][col] == 'B')
            break ;
        if (board[row][col] == 'R' || board[row][col] == 'Q')
            return (1);   
    }

	row = kx;
    col = ky;
    while (--row != -1 && ++col != len)
    {
        if (board[row][col] == 'P' || board[row][col] == 'R')
            break ;
        if (board[row][col] == 'B' || board[row][col] == 'Q')
            return (1) ;
    }
	row = kx;
    col = ky;
    while (--col != -1)
    {
        if (board[row][col] == 'P' || board[row][col] == 'B')
            break ;
        if (board[row][col] == 'R' || board[row][col] == 'Q')
            return (1) ;
    }
	   row = kx;
    col = ky;
    while (++col != len)
    {
        if (board[row][col] == 'P' || board[row][col] == 'B')
            break ;
        if (board[row][col] == 'R' || board[row][col] == 'Q')
            return (1) ;
    }
	row = kx;
    col = ky;
    while (++row != len && --col != -1)
    {
        if (board[row][col] == 'R')
            break ;
        if (board[row][col] == 'B' || board[row][col] == 'Q')
            return (1) ;
    }
	row = kx;
    col = ky;
    while (++row != len)
    {
        if (board[row][col] == 'P' || board[row][col] == 'B')
            break ;
        if (board[row][col] == 'R' || board[row][col] == 'Q')
            return (1) ;
    }
    row = kx;
    col = ky;
    while (++row != len && ++col != len)
    {
        if (board[row][col] == 'R')
            break ;
        if (board[row][col] == 'B' || board[row][col] == 'Q')
            return (1) ;
	}
	return (0);
}
#include <unistd.h>
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (check_mate(--argc, ++argv))
		write(1, "Success\n", 8);
	else
		write(1, "Fail\n", 5);
	return (0);
}
