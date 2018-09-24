/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 01:35:52 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/22 14:43:41 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	g_counter = 0;

int		check(int board[][8], int row, int col)
{
	int i;
	int j;

	i = 0;
	while (i < col)
		if (board[row][i++])
			return (0);
	i = row;
	j = col;
	while (j >= 0 && i >= 0)
		if (board[i--][j--])
			return (0);
	i = row;
	j = col;
	while (j >= 0 && i < 8)
		if (board[i++][j--])
			return (0);
	return (1);
}

void	initialize(int board[][8])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
			board[i][j++] = 0;
		i++;
	}
}

int		solve(int board[8][8], int col)
{
	int i;

	i = 0;
	if (col >= 8)
		return (1);
	while (i < 8)
	{
		if (check(board, i, col))
		{
			board[i][col] = 1;
			if (solve(board, col + 1))
				g_counter++;
			board[i][col] = 0;
		}
		i++;
	}
	return (0);
}

int		ft_eight_queens_puzzle(void)
{
	int chess[8][8];

	initialize(chess);
	solve(chess, 0);
	return (g_counter);
}
