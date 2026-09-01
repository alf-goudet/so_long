/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 20:22:13 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/01 21:04:07 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular(t_game *game)
{
	size_t	target_width;
	size_t	i;

	target_width = ft_strlen(game->map.grid[0]);
	i = 1;
	while (i < game->map.height)
	{
		game->map.width = ft_strlen(game->map.grid[i]);
		if (game->map.width != target_width)
			error_exit("Map is not rectangular", game);
		i++;
	}
}

void	check_walls(t_game *game)
{
	size_t	row_idx;
	size_t	col_idx;

	row_idx = 0;
	while (row_idx < game->map.height)
	{
		col_idx = 0;
		while (col_idx < game->map.width)
		{
			if (row_idx == 0 || row_idx == game->map.height - 1)
			{
				if (game->map.grid[row_idx][col_idx] != '1')
					error_exit("Map not completely covered in walls", game);
			}
			else if (col_idx == 0 || col_idx == game->map.width - 1)
			{
				if (game->map.grid[row_idx][col_idx] != '1')
					error_exit("Map not completely covered in walls", game);
			}
			col_idx++;
		}
		row_idx++;
	}
}
