/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:35:45 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/17 20:44:40 by agoudet-         ###   ########.fr       */
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
	ft_printf("Pressed key of code: %d\n", keycode);
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W || keycode == UP_ARROW)
		move_player(game, dx, --dy);
	else if (keycode == A || keycode == LEFT_ARROW)
		move_player(game, --dx, dy);
	else if (keycode == S || keycode == DOWN_ARROW)
		move_player(game, dx, ++dy);
	else if (keycode == D || keycode == RIGHT_ARROW)
		move_player(game, ++dx, dy);
	return (0);
}
