/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 19:58:40 by lchety            #+#    #+#             */
/*   Updated: 2017/05/29 10:26:44 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_block(t_fil *dna, int x, int y)
{
	if (x < 0 || x >= dna->map.w)
		return (0);
	if (y < 0 || y >= dna->map.h)
		return (0);
	if (dna->map.area[x][y].sign == dna->enemy_char)
		return (0);
	if (dna->map.area[x][y].sign == dna->player_char)
		dna->move.weld++;
	return (1);
}

int		test_each_block(t_fil *dna, int tabx, int taby)
{
	int x;
	int y;
	int score;

	dna->move.weld = 0;
	y = -1;
	score = 0;
	while (++y < dna->piece.h)
	{
		x = 0;
		while (x < dna->piece.w)
		{
			if (dna->piece.tab[x][y] == '*')
			{
				if (!check_block(dna, tabx + x, taby + y))
					return (0);
				score += dna->map.area[tabx + x][taby + y].score;
			}
			x++;
		}
	}
	if (dna->move.weld == 1)
		return ((score) ? score : 1);
	return (0);
}

void	check_move(t_fil *dna)
{
	int x;
	int y;
	int score;

	reset_move(dna);
	y = 0 - dna->piece.h;
	while (y < dna->map.h - 1)
	{
		x = 0 - dna->piece.w;
		while (x < dna->map.w - 1)
		{
			if ((score = test_each_block(dna, x, y)))
			{
				if (score > dna->move.score)
				{
					dna->move.score = score;
					dna->move.x = x;
					dna->move.y = y;
				}
			}
			x++;
		}
		y++;
	}
}
