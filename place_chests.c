/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_chests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:55:37 by alexigar          #+#    #+#             */
/*   Updated: 2024/04/04 12:42:00 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_chest(mlx_texture_t *chest, int x, int y, t_player_info_t *player)
{
	t_collectible_t	*new;
	mlx_image_t		*img;
	static int		i = 0;

	img = mlx_texture_to_image(player -> window, chest);
	new = malloc(sizeof(t_collectible_t *));
	if (!new || mlx_image_to_window(player -> window, img, x, y) < 0)
		error_loading();
	else
	{
		new -> positionx = x;
		new -> positiony = y;
		new -> img = img;
	}
	player -> collect_img[i] = new;
	i++;
}
