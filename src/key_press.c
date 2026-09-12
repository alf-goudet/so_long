/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:35:45 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/12 19:27:16 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, void *param)
{
	t_game	*game;
	int		dx;
	int		dy;

	game = (t_game *)param;
	dx = (int)game->map.player_start_x;
	dy = (int)game->map.player_start_y;
	if (keycode == ESC)
		close_game(game);
	else
		move_player(game, keycode, dx, dy);
	return (0);
}
