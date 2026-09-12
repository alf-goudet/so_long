/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 18:46:54 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/12 19:13:11 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *g, int keycode, int dx, int dy)
{
	if (keycode == W)
		ft_printf("Up pressed: Moving to position (%d,%d)\n", dx, dy++);
	else if (keycode == A)
		ft_printf("Left pressed: Moving to position (%d,%d)\n", dx--, dy);
	else if (keycode == S)
		ft_printf("Down pressed: Moving to position (%d,%d)\n", dx, dy--);
	else if (keycode == D)
		ft_printf("Right pressed: Moving to position (%d,%d)\n", dx++, dy);
	else
		ft_printf("Wrong key. Cannot move player %p\n", g->img_player);
}
