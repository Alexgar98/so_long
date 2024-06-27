/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:45:39 by alexigar          #+#    #+#             */
/*   Updated: 2024/04/19 12:48:31 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_ber(char *file)
{
	char	*next_line;
	char	*to_split;
	int		fd;
	char	**map;

	next_line = NULL;
	to_split = NULL;
	map = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	next_line = get_next_line(fd);
	if (!next_line)
		return (NULL);
	to_split = read_everything(next_line, fd);
	close(fd);
	map = ft_split(to_split, '\n');
	return (map);
}

int	check_valid_args(int argc, char **argv)
{
	char	*ber;

	if (argc == 2)
	{
		ber = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
		if (!ber || ft_strlen(ber) != 4)
			invalid_file();
	}
	else
		invalid_args();
	return (1);
}

int	check_valid_map(char **map, t_player_info_t *player)
{
	int	collectibles;

	collectibles = check_valid_items(map);
	if (!check_valid_lines(map) || !check_borders(map) || !collectibles)
	{
		player -> position = ft_calloc(1, sizeof(int));
		return (0);
	}
	if (endgame_reachable(map, collectibles, player))
	{
		player -> map = map;
		player -> collectibles = collectibles;
		return (1);
	}
	else
	{
		player -> map = ft_calloc(1, sizeof(char));
		return (0);
	}
	return (1);
}

void	run_window(char **map, t_player_info_t *player)
{
	int				i;
	int				j;
	mlx_t			*window;

	i = 32 * ft_strlen(map[0]);
	j = 0;
	while (map[j])
		j++;
	j *= 32;
	window = mlx_init(i, j, "so_long", 0);
	player -> window = window;
	generate_floor(player -> window, map);
	generate_walls(player -> window, map);
	player -> collect_img = malloc(sizeof(t_collectible_t **)
			* player -> collectibles);
	if (!(player -> collect_img))
		error_loading();
	place_collectibles(map, player);
	place_exit(player -> window, map);
	player -> character_img = place_character(player -> window, map);
	player -> movements = 0;
	mlx_loop_hook(player -> window, ft_hook, player);
	mlx_loop(player -> window);
	mlx_terminate(player -> window);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	char			**map;
	t_player_info_t	*player;

	map = NULL;
	player = malloc(sizeof(t_player_info_t));
	if (!player)
		error_loading();
	check_valid_args(argc, argv);
	map = read_ber(argv[1]);
	if (!map)
	{
		not_file();
		free_player(player);
	}
	if (!check_valid_map(map, player))
	{
		free_map(map);
		free_player(player);
		invalid_map();
	}
	else
		run_window(map, player);
	free_map(map);
	free_player(player);
	return (0);
}
