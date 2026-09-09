/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 20:29:16 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/08 18:02:18 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_floor(t_game *game, int x, int y)
{
	void	*mlx;
	void	*win;
	int		pix_x;
	int		pix_y;

	mlx = game->mlx_ptr;
	win = game->win_ptr;
	pix_x = x * TILE_SIZE;
	pix_y = y * TILE_SIZE;
	mlx_put_image_to_window(mlx, win, game->img_floor, pix_x, pix_y);
}

static void	render_element(t_game *game, int x, int y)
{
	char	**grid;
	void	*mlx;
	void	*win;
	int		pix_x;
	int		pix_y;

	grid = game->map.grid;
	mlx = game->mlx_ptr;
	win = game->win_ptr;
	pix_x = x * TILE_SIZE;
	pix_y = y * TILE_SIZE;
	if (grid[y][x] == '0')
		return ;
	else if (grid[y][x] == '1')
		mlx_put_image_to_window(mlx, win, game->img_wall, pix_x, pix_y);
	else if (grid[y][x] == 'P')
		mlx_put_image_to_window(mlx, win, game->img_player, pix_x, pix_y);
	else if (grid[y][x] == 'C')
		mlx_put_image_to_window(mlx, win, game->img_collect, pix_x, pix_y);
	else if (grid[y][x] == 'E')
		mlx_put_image_to_window(mlx, win, game->img_exit, pix_x, pix_y);
}

static int	end_loop(int keycode, void *param)
{
	void	*mlx_ptr;

	mlx_ptr = param;
	ft_printf("Pressed key of code %x\n", keycode);
	if (keycode == 0x20)
		mlx_loop_end(mlx_ptr);
	return (0);
}

void	render_map(t_game *game)
{
	int		floor_fully_rendered;
	size_t	x;
	size_t	y;

	floor_fully_rendered = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (!floor_fully_rendered)
				render_floor(game, (int)x, (int)y);
			else
				render_element(game, (int)x, (int)y);
			x++;
		}
		y++;
		if (y == game->map.height)
		{
			mlx_key_hook(game->win_ptr, &end_loop, game->mlx_ptr);
			mlx_loop(game->mlx_ptr);
			floor_fully_rendered = 1;
			y = 0;
		}
	}
}
