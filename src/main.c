/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:22:35 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/31 21:51:06 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h> // for explicit true/false boolean values

static void	init_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	ft_bzero(&game->map, sizeof(t_map));
	game->move_count = 0;
	game->img_ptrs = NULL;
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

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (argc != 2)
		error_exit("Missing map argument (.ber)", &game);
	if (!file_ext_is_ber(argv[1]))
		error_exit("Map argument doesn't end in .ber", &game);
	read_map(argv[1], &game);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		error_exit("mlx_init failed", &game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, 800, 600, "so_long");
	if (!game.win_ptr)
		error_exit("Window creation failed", &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
