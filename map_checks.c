/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:56:11 by alexigar          #+#    #+#             */
/*   Updated: 2024/04/19 10:10:00 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_lines(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (map[j])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[j]))
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	check_borders(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (j < ft_strlen(map[i]))
		{
			if (i == 0 || j == 0 || j == (ft_strlen(map[i]) - 1)
				|| !map[i + 1])
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

void	count_items(char **map, int *c, int *e, int *p)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		//ft_printf("%s\n", map[i]);
		while (j < ft_strlen(map[0]))
		{
			if (map[i][j] == 'C')
				c[0]++;
			else if (map[i][j] == 'E')
				e[0]++;
			else if (map[i][j] == 'P')
				p[0]++;
			else if (map[i][j] != '0' && map[i][j] != '1')
			{
				invalid_map();
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	check_valid_items(char **map)
{
	int		c;
	int		e;
	int		p;

	c = 0;
	e = 0;
	p = 0;
	count_items(map, &c, &e, &p);
	if (c < 1 || e != 1 || p != 1)
		return (0);
	return (c);
}

int	endgame_reachable(char **map, int collectibles, t_player_info_t *player)
{
	int	*start;
	int	x;
	int	y;

	start = find_position('P', map);
	x = start[0];
	y = start[1];
	player -> position = start;
	if (check_endgame(x, y, map)
		&& check_collectibles(x, y, map) == collectibles)
		return (1);
	else
	{
		free(start);
		return (0);
	}
}
