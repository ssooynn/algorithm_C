/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooylee <sooylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:49:04 by sooylee           #+#    #+#             */
/*   Updated: 2021/10/24 18:49:05 by sooylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_the_row(int board[10], int n)
{
	int		i;
	char	ch;

	i = 0;
	while (i < n)
	{	
		ch = board[i] + '0';
		write(1, &ch, 1);
		i ++;
	}
	write(1, &"\n", 1);
}

int	is_valid(int board[10], int row, int n)
{
	int	i;
	int	diff;

	i = 0;
	while (i < row)
	{
		diff = board[i] - board[row];
		if (diff == 0)
			return (0);
		if ((diff == row - i) || (diff == -(row - i)))
			return (0);
		i ++;
	}
	return (1);
}

int	place_the_queen(int board[10], int row, int n)
{	
	int	count;
	int	col;

	count = 0;
	col = 0;
	if (n == row)
	{
		print_the_row(board, n);
		return (1);
	}
	while (col < n)
	{
		board[row] = col;
		if (is_valid(board, row, n))
			count += place_the_queen(board, row + 1, n);
		col ++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	answer;
	int	i;

	i = 0;
	while (i < 10)
	{
		board[i] = 0;
		i ++;
	}
	answer = place_the_queen(board, 0, 10);
	return (answer);
}
