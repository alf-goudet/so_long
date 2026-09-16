/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:35:45 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/14 20:56:16 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, void *param)
{
	t_game	*game;
	int		dx;
	int		dy;

	game = (t_game *)param;
	dx = 0;
	dy = 0;
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W)
		move_player(game, dx, --dy);
	else if (keycode == A)
		move_player(game, --dx, dy);
	else if (keycode == S)
		move_player(game, dx, ++dy);
	else if (keycode == D)
		move_player(game, ++dx, dy);
	return (0);
}
