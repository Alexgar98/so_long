/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:44:48 by alexigar          #+#    #+#             */
/*   Updated: 2024/04/18 17:37:00 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	map = NULL;
}

void	free_player(t_player_info_t *player)
{
	if (player -> map)
		player -> map = NULL;
	if (player -> collect_img)
		player -> collect_img = NULL;
	if (player -> position)
	{
		free(player -> position);
		player -> position = NULL;
	}
	free(player);
}

void	free_collectibles(t_collectible_t **collectibles)
{
	int	i;

	i = 0;
	while (collectibles[i])
	{
		free(collectibles[i]);
		collectibles[i] = NULL;
		i++;
	}
	free(collectibles);
	collectibles = NULL;
}
