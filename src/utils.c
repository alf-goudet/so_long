/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 17:33:14 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/03 19:02:19 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_grid(t_game *game, char **grid_copy)
{
	size_t	i;

	i = 0;
	while (i < game->map.height)
	{
		grid_copy[i] = ft_strdup(game->map.grid[i]);
		if (grid_copy[i] == NULL)
		{
			free_map(grid_copy, i);
			error_exit("ft_strdup", game);
		}
		i++;
	}
}

char	**copy_and_fill_grid(t_game *game)
{
	char	**grid_copy;
	size_t	player_start_x;
	size_t	player_start_y;

	grid_copy = (char **)malloc(game->map.height * sizeof(char *));
	if (grid_copy == NULL)
		error_exit("malloc", game);
	copy_grid(game, grid_copy);
	player_start_x = game->map.player_start_x;
	player_start_y = game->map.player_start_y;
	flood_fill(grid_copy, player_start_x, player_start_y);
	return (grid_copy);
}

void	free_map(char **grid, size_t row_allocs)
{
	size_t	i;

	i = 0;
	while (i < row_allocs)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
