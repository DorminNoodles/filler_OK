/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:20:23 by lchety            #+#    #+#             */
/*   Updated: 2017/05/29 10:08:26 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	reset_move(t_fil *dna)
{
	dna->move.score = 0;
	dna->move.x = 0;
	dna->move.y = 0;
}

void	reset(t_fil *dna)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (y < dna->map.h)
	{
		x = 0;
		while (x < dna->map.w)
		{
			dna->map.area[x][y].score = 0;
			x++;
		}
		y++;
	}
}

void	free_split(char **split)
{
	ft_memdel((void**)&split[0]);
	ft_memdel((void**)&split[1]);
	ft_memdel((void**)&split[2]);
	ft_memdel((void**)&split);
}
