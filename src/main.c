/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:22:35 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/27 21:38:40 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	file_ext_is_ber(char *file_name)
{
	char	*file_ext;

	file_ext = ft_strrchr(file_name, '.');
	if (ft_strncmp(file_ext, ".ber", 5) == 0)
		return (true);
	else
		return (false);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;

	if (argc != 2)
		print_error_and_exit("Missing map argument (.ber)");
	if (!file_ext_is_ber(argv[1]))
		print_error_and_exit("Map argument doesn't end in .ber");
	mlx = mlx_init();
	if (mlx == NULL)
		print_error_and_exit("mlx_init failed");
	window = mlx_new_window(mlx, 800, 600, "so_long");
	if (window == NULL)
	{
		free(mlx);
		print_error_and_exit("Window creation failed");
	}
	mlx_loop(mlx);
	return (0);
}
