/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 18:46:54 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/14 17:50:22 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *g, int move_x, int move_y)
{
	int		player_x;
	int		player_y;
	int		new_x;
	int		new_y;

	player_x = g->map.player_pos_x;
	player_y = g->map.player_pos_y;
	new_x = player_x + move_x;
	new_y = player_y + move_y;
	if (g->map.grid[new_x][new_y] == '1')
		return ;
	else
	{
		g->map.grid[player_x][player_y] = '0';
		g->map.grid[new_x][new_y] = 'P';
		g->map.player_pos_x = new_x;
		g->map.player_pos_y = new_y;
		mlx_clear_window(g->mlx_ptr, g->win_ptr);
		render_map(g);
	}
}
