/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 18:46:54 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/15 16:57:45 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	change_old_pos(t_map map, int old_x, int old_y);

static void	check_win_conditions(t_game *g);

void	move_player(t_game *g, int move_x, int move_y)
{
	int			old_x;
	int			old_y;
	int			new_x;
	int			new_y;

	old_x = g->map.player_pos_x;
	old_y = g->map.player_pos_y;
	new_x = old_x + move_x;
	new_y = old_y + move_y;
	if (g->map.grid[new_y][new_x] == '1')
		return ;
	if (g->map.grid[new_y][new_x] == 'C')
		g->collected++;
	g->map.grid[old_y][old_x] = change_old_pos(g->map, old_x, old_y);
	g->map.grid[new_y][new_x] = 'P';
	g->map.player_pos_x = new_x;
	g->map.player_pos_y = new_y;
	mlx_clear_window(g->mlx_ptr, g->win_ptr);
	render_map(g);
	g->move_count++;
	ft_printf("Moves: %d\n", g->move_count);
	check_win_conditions(g);
}

static char	change_old_pos(t_map map, int old_x, int old_y)
{
	size_t	exit_x;
	size_t	exit_y;

	exit_x = map.exit_pos_x;
	exit_y = map.exit_pos_y;
	if (map.grid[old_y][old_x] == map.grid[exit_y][exit_x])
		return ('E');
	else
		return ('0');
}

static void	check_win_conditions(t_game *g)
{
	size_t	player_x;
	size_t	player_y;
	size_t	exit_x;
	size_t	exit_y;

	player_x = g->map.player_pos_x;
	player_y = g->map.player_pos_y;
	exit_x = g->map.exit_pos_x;
	exit_y = g->map.exit_pos_y;
	if (g->map.grid[player_y][player_x] == g->map.grid[exit_y][exit_x]
		&& g->collected == g->map.collects)
	{
		ft_printf("Game Clear!\n");
		close_game(g);
	}
}
