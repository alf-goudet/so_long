/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:19:50 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/01 21:37:23 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (game->img_ptrs[i] != NULL)
	{
		mlx_destroy_image(game->mlx_ptr, game->img_ptrs[i]);
		i++;
	}
}

static void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
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
	if (game->img_ptrs)
		destroy_images(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	if (game->map.grid)
		free_map(&(game->map));
	exit(EXIT_FAILURE);
}
