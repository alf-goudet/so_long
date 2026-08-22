/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:38:19 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/22 22:34:18 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "keys.h" // where ON_LINUX flag macro is defined according to OS

static void	destroy_all_images(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->img_count)
	{
		mlx_destroy_image(data->mlx_ptr, data->images[i]);
		i++;
	}
}

void	close_game(t_data *data)
{
	destroy_all_images(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (ON_LINUX)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}
