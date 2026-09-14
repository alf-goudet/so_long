/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:22:35 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/14 17:27:01 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	ft_bzero(&game->map, sizeof(t_map));
	game->move_count = 0;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_collect = NULL;
	game->img_exit = NULL;
}

static bool	file_ext_is_ber(char *file_name)
{
	char	*file_ext;

	file_ext = ft_strrchr(file_name, '.');
	if (!file_ext)
		return (true);
	else
	{
		if (ft_strncmp(file_ext, ".ber", 5) == 0)
			return (true);
		else
			return (false);
	}
}

static void	run_graphics(t_game *game)
{
	int	width;
	int	height;

	width = game->map.width * TILE_SIZE;
	height = game->map.height * TILE_SIZE;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_exit("mlx_init failed", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, "so_long");
	if (!game->win_ptr)
		error_exit("Window creation failed", game);
	load_images(game);
	render_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (argc != 2)
		error_exit("Missing map argument (.ber)", &game);
	if (!file_ext_is_ber(argv[1]))
		error_exit("Map argument doesn't end in .ber", &game);
	read_map(argv[1], &game);
	run_graphics(&game);
	mlx_hook(game.win_ptr, DESTROY_NOTIFY, NO_EVENT_MASK, &close_game, &game);
	mlx_key_hook(game.win_ptr, &key_press, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
