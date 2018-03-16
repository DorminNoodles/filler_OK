/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 22:47:17 by lchety            #+#    #+#             */
/*   Updated: 2017/05/29 11:09:02 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_000(char **line)
{
	while (!ft_strstr(*line, "000 "))
	{
		ft_memdel((void**)line);
		get_next_line(0, line);
		if (!*line)
			return (0);
	}
	return (1);
}

int		init_game(t_fil *dna, char **line)
{
	init_dna(dna);
	if (!get_players(dna, line))
		return (0);
	if (!get_map_size(dna, line))
		return (0);
	if (!create_area(dna))
		return (0);
	return (1);
}

void	init_dna(t_fil *dna)
{
	dna->player = 0;
	dna->map.area = NULL;
	dna->move.x = 0;
	dna->move.y = 0;
	dna->move.score = 0;
}

int		create_area(t_fil *dna)
{
	int		x;
	int		y;
	t_case	**area;

	x = 0;
	if (!(area = (t_case**)ft_memalloc(sizeof(t_case*) * dna->map.w)))
		return (0);
	while (x < dna->map.w)
	{
		if (!(*(area + x) = (t_case*)ft_memalloc(sizeof(t_case) * dna->map.h)))
			return (0);
		y = 0;
		while (y < dna->map.h)
		{
			area[x][y].sign = '.';
			area[x][y].score = 0;
			y++;
		}
		x++;
	}
	dna->map.area = area;
	return (1);
}

int		main(void)
{
	t_fil	dna;
	char	*line;

	line = NULL;
	dna.map.area = NULL;
	while (get_next_line(0, &line))
	{
		if (!dna.map.area)
			if (!(init_game(&dna, &line)))
				return (0);
		if (dna.map.area)
			reset(&dna);
		if (!pars_map(&dna, &line))
			return (0);
		if (!pars_piece(&dna, &line))
			return (0);
		play(&dna);
	}
	return (0);
}
