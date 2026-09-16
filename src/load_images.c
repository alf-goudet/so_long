/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 20:27:49 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/15 17:31:09 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_image(t_game *game, char *file, int width, int height)
{
	void	*mlx_ptr;
	void	*img_ptr;

	mlx_ptr = game->mlx_ptr;
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, file, &width, &height);
	if (img_ptr == NULL)
		error_exit("Failed to load sprite", game);
	return (img_ptr);
}

void	load_images(t_game *game)
{
	const int	wid = TILE_SIZE;
	const int	hei = TILE_SIZE;

	game->img_wall = load_image(game, "textures/wall.xpm", wid, hei);
	game->img_floor = load_image(game, "textures/grass.xpm", wid, hei);
	game->img_player = load_image(game, "textures/character.xpm", wid, hei);
	game->img_collect = load_image(game, "textures/coin.xpm", wid, hei);
	game->img_exit = load_image(game, "textures/chest.xpm", wid, hei);
}
