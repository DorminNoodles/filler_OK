/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:48:50 by lchety            #+#    #+#             */
/*   Updated: 2017/05/29 11:02:11 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_piece_split(char **split)
{
	if (!split[1])
		return (0);
	if (!split[2])
		return (0);
	return (1);
}

int		piece_length(t_fil *dna, char **line)
{
	char	**split;

	while (!ft_strstr(*line, "Piece"))
	{
		ft_memdel((void**)line);
		get_next_line(0, line);
	}
	if (!check_piece_split(split = ft_strsplit(*line, ' ')))
		return (0);
	dna->piece.w = ft_atoi(split[2]);
	dna->piece.h = ft_atoi(split[1]);
	free_tab(split, 3);
	return (1);
}

void	add_piece(t_fil *dna, int x, int y, char c)
{
	if (dna->map.area[x][y].sign != c && c == dna->enemy_char)
		dna->map.area[x][y].sign = dna->enemy_char;
	if (dna->map.area[x][y].sign != c && c == dna->player_char)
		dna->map.area[x][y].sign = dna->player_char;
}
