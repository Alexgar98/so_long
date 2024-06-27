/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:07:24 by alexigar          #+#    #+#             */
/*   Updated: 2024/04/08 12:21:20 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_sprite(t_player_info_t *player, mlx_texture_t *texture)
{
	mlx_image_t	*new;

	mlx_delete_image(player -> window, player -> character_img);
	if (!texture)
		error_loading();
	new = mlx_texture_to_image(player -> window, texture);
	player -> character_img = new;
	if (!new)
		error_loading();
	mlx_image_to_window(player -> window, new, player -> position[1] * 32,
		player -> position[0] * 32);
}

void	animation_hook(t_player_info_t *player, int frame)
{
	static int		sprite = 0;
	mlx_texture_t	*texture;

	if (frame % 10 == 0)
	{
		if (sprite % 6 == 0)
			texture = mlx_load_png("./textures/dorumon1.png");
		else if (sprite % 6 == 1)
			texture = mlx_load_png("./textures/dorumon2.png");
		else if (sprite % 6 == 2)
			texture = mlx_load_png("./textures/dorumon3.png");
		else if (sprite % 6 == 3)
			texture = mlx_load_png("./textures/dorumon4.png");
		else if (sprite % 6 == 4)
			texture = mlx_load_png("./textures/dorumon5.png");
		else
			texture = mlx_load_png("./textures/dorumon6.png");
		sprite++;
		change_sprite(player, texture);
		mlx_delete_texture(texture);
	}
}
