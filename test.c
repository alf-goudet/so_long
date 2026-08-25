/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:48:36 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/25 20:28:56 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "keys.h" // Linux and macOS cross-compatible keycode values

/*
 * 1. [x] Check if the number of arguments is 2. Otherwise ask user for a map.
 * 2. [x] Check that the given filename ends in a NUL-terminated .ber.
 * 3. [x] Assign a file descriptor to the given map file.
 * 4. [x] Allocate memory for a 2D char buffer.
 * 5. [x] Read the map file into said buffer.
 * 6. [ ] Verify that the given map is valid according to the subject.
 * 		6.1. [x] Verify that there aren't any characters other than '1', '0',
 *			'P', 'C' and 'E'.
 *		6.2. [x] Verify that the edges are entirely made of walls (to prevent
 *			moving out of bounds).
 *			6.2.1. [x] The first and last lines should be made entirely of
 *				walls.
 *			6.2.2. [x] The lines between the first and the last must have a
 *				wall in their first and last characters.
 *		6.3. [x] Verify the existence of one 'P', one 'E' and at least one 'C'.
 *      6.4. [ ] Verify if the map has a valid path to clear the game. In this
 *				 path, all game clear objectives should be attainable:
 *			6.4.1. [ ] Collect all collectibles.
 *			6.4.2. [ ] Reach the exit.
 */

static int	print_on_esc_key(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == ESC_KEY)
	{
		mlx_loop_end(data->mlx_ptr);
	}
	return (0);
}

static void	manage_game_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		perror("mlx_init");
		free_map_array(data->map_desc, data->num_rows);
		exit(EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "Test Window");
	if (data->win_ptr == NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		perror("mlx_new_window");
		free(data->mlx_ptr);
		free_map_array(data->map_desc, data->num_rows);
		exit(EXIT_FAILURE);
	}
	mlx_key_hook(data->win_ptr, &print_on_esc_key, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		exit(no_map_error(argv[0]));
	data.file_name = argv[1];
	validate_file_name(data.file_name);
	count_rows(&data);
	data.fd = open_map_file(data.file_name);
	prep_map_array(&data);
	close_and_handle_error(&data);
	validate_map(&data);
	free_map_array(data.map_desc, data.num_rows);
	manage_game_window(&data);
	return (0);
}
