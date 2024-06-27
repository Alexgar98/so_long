/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:44:48 by alexigar          #+#    #+#             */
/*   Updated: 2024/04/08 12:07:36 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "utils/libft/libft.h"
# include "utils/ft_printf/ft_printf.h"
# include "utils/get_next_line/get_next_line.h"

typedef struct t_collectible
{
	mlx_image_t	*img;
	int			positionx;
	int			positiony;
}	t_collectible_t;

typedef struct t_player_info
{
	mlx_t			*window;
	char			**map;
	int				*position;
	int				collectibles;
	int				movements;
	mlx_image_t		*character_img;
	t_collectible_t	**collect_img;
}	t_player_info_t;

char		**read_ber(char *file);
int			check_valid_args(int argc, char **argv);
int			check_valid_map(char **map, t_player_info_t *player);
void		run_window(char **map, t_player_info_t *player);
void		invalid_map(void);
void		not_file(void);
void		invalid_file(void);
void		invalid_args(void);
void		error_loading(void);
int			*find_position(char item, char **map);
int			check_endgame(int x, int y, char **map);
int			check_collectibles(int x, int y, char **map);
void		generate_floor(mlx_t *window, char **map);
void		generate_walls(mlx_t *window, char **map);
void		place_collectibles(char **map,
				t_player_info_t *player);
void		place_exit(mlx_t *window, char **map);
mlx_image_t	*place_character(mlx_t *window, char **map);
int			check_valid_lines(char **map);
int			check_borders(char **map);
void		count_items(char **map, int *c, int *e, int *p);
int			check_valid_items(char **map);
int			endgame_reachable(char **map, int collectibles,
				t_player_info_t *player);
void		replace_character(t_player_info_t *player, int x, int y);
void		check_got_something(t_player_info_t *player, int x, int y);
void		ft_key_hook(void *param, int frame);
void		ft_hook(void *param);
void		destroy_chest(t_collectible_t **chests, t_player_info_t *player,
				int x, int y);
void		place_chest(mlx_texture_t *chest, int x, int y,
				t_player_info_t *player);
void		animation_hook(t_player_info_t *player, int frame);
void		change_sprite(t_player_info_t *player, mlx_texture_t *texture);
void		free_map(char **map);
void		free_player(t_player_info_t *player);
void		free_collectibles(t_collectible_t **collectibles);
char		*read_everything(char *next_line, int fd);

#endif