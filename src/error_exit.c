/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:19:50 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/14 12:35:06 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx_ptr, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx_ptr, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx_ptr, game->img_player);
	if (game->img_collect)
		mlx_destroy_image(game->mlx_ptr, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
}

void	error_exit(char *msg, t_game *game)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	if (!errno)
		ft_putendl_fd(msg, STDERR_FILENO);
	else if (errno == EACCES)
		perror("Couldn't read map");
	else
		perror(msg);
	destroy_images(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	if (game->map.grid)
		free_map(game->map.grid, game->map.height);
	exit(EXIT_FAILURE);
}
