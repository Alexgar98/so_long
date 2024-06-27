/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:19:03 by alexigar          #+#    #+#             */
/*   Updated: 2024/04/01 12:15:46 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map(void)
{
	ft_printf("Error\nInvalid map provided");
	exit(EXIT_FAILURE);
}

void	not_file(void)
{
	ft_printf("Error\nCould not read file");
	exit(EXIT_FAILURE);
}

void	invalid_file(void)
{
	ft_printf("Error\nInvalid file provided");
	exit(EXIT_FAILURE);
}

void	invalid_args(void)
{
	ft_printf("Error\nNo file provided, or wrong args");
	exit(EXIT_FAILURE);
}

void	error_loading(void)
{
	ft_printf("Error\nCould not load something");
	exit(EXIT_FAILURE);
}
