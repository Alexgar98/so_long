/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:55:36 by alexigar          #+#    #+#             */
/*   Updated: 2024/04/19 10:16:04 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_everything(char *next_line, int fd)
{
	char	*aux;
	char	*to_split;

	aux = NULL;
	to_split = NULL;
	to_split = ft_calloc(1, sizeof(char));
	while (next_line)
	{
		if (next_line && next_line[0] != '\n')
		{
			aux = ft_strjoin(to_split, next_line);
			free(to_split);
			to_split = aux;
		}
		else
		{
			free(to_split);
			invalid_map();
		}
		free(next_line);
		next_line = get_next_line(fd);
	}
	free(aux);
	return (to_split);
}
