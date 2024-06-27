/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:45:20 by alexigar          #+#    #+#             */
/*   Updated: 2024/04/05 12:35:36 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	generate_floor(mlx_t *window, char **map)
{
	mlx_texture_t	*texture;
	mlx_image_t		*floor;
	int				x;
	int				y;

	texture = mlx_load_png("./textures/grass.png");
	if (!texture)
		error_loading();
	floor = mlx_texture_to_image(window, texture);
	x = 0;
	y = 0;
	if (!floor || (mlx_image_to_window(window, floor, 0, 0) < 0))
		error_loading();
	while (map[y])
	{
		while (map[y][x])
		{
			mlx_image_to_window(window, floor, x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_delete_texture(texture);
}

void	generate_walls(mlx_t *window, char **map)
{
	mlx_texture_t	*texture;
	mlx_image_t		*wall;
	int				x;
	int				y;

	texture = mlx_load_png("./textures/tree.png");
	if (!texture)
		error_loading();
	wall = mlx_texture_to_image(window, texture);
	x = 0;
	y = -1;
	if (!wall)
		error_loading();
	while (map[++y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '1')
				if (mlx_image_to_window(window, wall, x * 32, y * 32) < 0)
					error_loading();
			x++;
		}
		x = 0;
	}
	mlx_delete_texture(texture);
}

void	place_collectibles(char **map, t_player_info_t *player)
{
	mlx_texture_t	*texture;
	int				x;
	int				y;

	texture = mlx_load_png("./textures/chest.png");
	if (!texture)
		error_loading();
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'c')
				place_chest(texture, x * 32, y * 32, player);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_delete_texture(texture);
}

void	place_exit(mlx_t *window, char **map)
{
	mlx_texture_t	*texture;
	mlx_image_t		*stairs;
	int				x;
	int				y;

	texture = mlx_load_png("./textures/stairs.png");
	if (!texture)
		error_loading();
	stairs = mlx_texture_to_image(window, texture);
	x = 0;
	y = -1;
	if (!stairs)
		error_loading();
	while (map[++y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'e')
				if (mlx_image_to_window(window, stairs, x * 32, y * 32) < 0)
					error_loading();
			x++;
		}
		x = 0;
	}
	mlx_delete_texture(texture);
}

mlx_image_t	*place_character(mlx_t *window, char **map)
{
	mlx_texture_t	*texture;
	mlx_image_t		*dorumon;
	int				x;
	int				y;

	texture = mlx_load_png("./textures/dorumon1.png");
	if (!texture)
		error_loading();
	dorumon = mlx_texture_to_image(window, texture);
	x = 0;
	y = -1;
	if (!dorumon)
		error_loading();
	while (map[++y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'p')
				mlx_image_to_window(window, dorumon, x * 32, y * 32);
			x++;
		}
		x = 0;
	}
	mlx_delete_texture(texture);
	return (dorumon);
}
