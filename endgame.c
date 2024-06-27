/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:15:02 by alexigar          #+#    #+#             */
/*   Updated: 2024/04/02 11:24:10 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*find_position(char item, char **map)
{
	int	i;
	int	j;
	int	*to_return;

	i = 0;
	j = 0;
	to_return = malloc(sizeof(int) * 2);
	if (!to_return)
		return (NULL);
	while (map[i][j] != item)
	{
		while (j < (int)ft_strlen(map[i]))
		{
			j++;
			if (map[i][j] == item)
			{
				to_return[0] = i;
				to_return[1] = j;
				return (to_return);
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}

int	check_endgame(int x, int y, char **map)
{
	if (!map[x] || !map[x][y])
		return (0);
	if (map[x][y] == '1')
		return (0);
	if (map[x][y] == 'E')
		return (1);
	if (map[x][y] == '2')
		return (0);
	if (map[x][y] == '0')
		map[x][y] = '2';
	if (check_endgame(x + 1, y, map) == 1)
		return (1);
	else if (check_endgame(x - 1, y, map) == 1)
		return (1);
	else if (check_endgame(x, y + 1, map) == 1)
		return (1);
	else if (check_endgame(x, y - 1, map) == 1)
		return (1);
	else
		return (0);
}

int	check_collectibles(int x, int y, char **map)
{
	int	found;

	found = 0;
	if (!map[x] || !map[x][y] || map[x][y] == '1' || map[x][y] == 'c' ||
		map[x][y] == '3' || map[x][y] == 'p' || map[x][y] == 'e')
		return (0);
	if (map[x][y] == 'C')
	{
		found += 1;
		map[x][y] = 'c';
	}
	else
	{
		if (map[x][y] == '2' || map[x][y] == '0')
			map[x][y] = '3';
		if (map[x][y] == 'P')
			map[x][y] = 'p';
		if (map[x][y] == 'E')
			map[x][y] = 'e';
	}
	found += check_collectibles(x + 1, y, map);
	found += check_collectibles(x - 1, y, map);
	found += check_collectibles(x, y + 1, map);
	found += check_collectibles(x, y - 1, map);
	return (found);
}
