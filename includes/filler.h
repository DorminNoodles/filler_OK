/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 22:51:53 by lchety            #+#    #+#             */
/*   Updated: 2017/06/01 10:17:31 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include "libft.h"
# include "get_next_line.h"

# define BUFFER_PIECE 256
# define CLOSED 2
# define NEAR_SCORE 2

typedef struct	s_case
{
	char	sign;
	int		score;
}				t_case;

typedef struct	s_map
{
	int		w;
	int		h;
	t_case	**area;
}				t_map;

typedef struct	s_move
{
	int x;
	int y;
	int score;
	int weld;

}				t_move;

typedef struct	s_piece
{
	int		w;
	int		h;
	char	tab[BUFFER_PIECE][BUFFER_PIECE];
}				t_piece;

typedef struct	s_fil
{
	int		player;
	t_map	map;
	t_piece	piece;
	t_move	move;
	char	enemy_char;
	char	player_char;
}				t_fil;

void			init_dna(t_fil *dna);
int				init_game(t_fil *dna, char **line);
void			reset(t_fil *dna);
void			parsing(t_fil *dna, char **line);
void			play(t_fil *dna);
int				get_players(t_fil *dna, char **line);
int				get_map_size(t_fil *dna, char **line);
int				create_area(t_fil *dna);
void			check_move(t_fil *dna);
int				pars_piece(t_fil *dna, char **line);
int				pars_map(t_fil *dna, char **line);
void			add_piece(t_fil *dna, int x, int y, char c);
int				check_piece_split(char **split);
void			free_tab(char **tab, int nb);
int				piece_length(t_fil *dna, char **line);
void			reset_move(t_fil *dna);
void			error(int signum);
int				find_000(char **line);
void			free_split(char **split);
#endif
