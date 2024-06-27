/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:52:21 by alexigar          #+#    #+#             */
/*   Updated: 2024/04/08 12:20:14 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	replace_character(t_player_info_t *player, int x, int y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*dorumon;

	mlx_delete_image(player -> window, player -> character_img);
	texture = mlx_load_png("./textures/dorumon1.png");
	if (!texture)
		error_loading();
	dorumon = mlx_texture_to_image(player -> window, texture);
	if (!dorumon
		|| (mlx_image_to_window(player -> window, dorumon, y * 32, x * 32) < 0))
		error_loading();
	player -> character_img = dorumon;
	player -> position[0] = x;
	player -> position[1] = y;
	mlx_delete_texture(texture);
}

void	destroy_chest(t_collectible_t **chests, t_player_info_t *player,
	int x, int y)
{
	int	i;

	i = 0;
	while (chests[i])
	{
		if ((chests[i]-> positionx == y * 32)
			&& (chests[i]-> positiony == x * 32))
		{
			mlx_delete_image(player -> window, chests[i]-> img);
			return ;
		}
		i++;
	}
}

void	check_got_something(t_player_info_t *player, int x, int y)
{
	if (player -> map[x][y] == 'c')
	{
		player -> collectibles--;
		destroy_chest(player -> collect_img, player, x, y);
		player -> map[x][y] = '0';
	}
	else if (player -> map[x][y] == 'p')
		player -> map[x][y] = '0';
	else if (player -> map[x][y] == 'e' && player -> collectibles == 0)
	{
		player -> movements++;
		ft_printf("Success! You finished with %d moves", player -> movements);
		exit(EXIT_SUCCESS);
	}
	player -> movements++;
	replace_character(player, x, y);
	ft_printf("Moves: %d\n", player -> movements);
}

void	ft_key_hook(void *param, int frame)
{
	t_player_info_t	*player;
	int				x;
	int				y;

	player = param;
	x = player -> position[0];
	y = player -> position[1];
	if (mlx_is_key_down(player -> window, MLX_KEY_ESCAPE))
		exit(EXIT_SUCCESS);
	if (frame % 5 == 0)
	{
		if (mlx_is_key_down(player -> window, MLX_KEY_S)
			&& player -> map[x + 1][y] != '1')
			check_got_something(player, x + 1, y);
		else if (mlx_is_key_down(player -> window, MLX_KEY_W)
			&& player -> map[x - 1][y] != '1')
			check_got_something(player, x - 1, y);
		else if (mlx_is_key_down(player -> window, MLX_KEY_A)
			&& player -> map[x][y - 1] != '1')
			check_got_something(player, x, y - 1);
		else if (mlx_is_key_down(player -> window, MLX_KEY_D)
			&& player -> map[x][y + 1] != '1')
			check_got_something(player, x, y + 1);
	}
}

void	ft_hook(void *param)
{
	t_player_info_t	*player;
	static int		frame = 0;

	player = param;
	frame++;
	animation_hook(player, frame);
	ft_key_hook(player, frame);
}
