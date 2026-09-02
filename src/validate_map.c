/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 20:22:13 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/02 13:51:59 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_game_elements(t_game *game, size_t row_idx, size_t col_idx);

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

void	check_chars(t_game *game)
{
	size_t	row_idx;
	size_t	col_idx;
	char	curr_chr;

	row_idx = 0;
	while (row_idx < game->map.height)
	{
		col_idx = 0;
		while (col_idx < game->map.width)
		{
			curr_chr = game->map.grid[row_idx][col_idx];
			if (curr_chr == '1' || curr_chr == '0' || curr_chr == 'P'
				|| curr_chr == 'E' || curr_chr == 'C')
				count_game_elements(game, row_idx, col_idx);
			else
				error_exit("Invalid character detected in map", game);
			col_idx++;
		}
		row_idx++;
	}
	if (!game->map.player_pos || !game->map.exit || !game->map.collects)
		error_exit("Missing player start, exit and/or collectibles", game);
}

static void	count_game_elements(t_game *game, size_t row_idx, size_t col_idx)
{
	if (game->map.grid[row_idx][col_idx] == 'P')
	{
		game->map.player_pos++;
		game->map.player_start_x = col_idx;
		game->map.player_start_y = row_idx;
	} 
	else if (game->map.grid[row_idx][col_idx] == 'E')
		game->map.exit++;
	else if (game->map.grid[row_idx][col_idx] == 'C')
		game->map.collects++;
	if (game->map.player_pos > 1 || game->map.exit > 1)
		error_exit("More than 1 player start/exit found", game);
}
