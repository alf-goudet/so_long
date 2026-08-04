/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:48:36 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/04 18:24:44 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * 1. [x] Check if the number of arguments is 2. Otherwise ask user for a map.
 * 2. [x] Check that the given filename ends in a NUL-terminated .ber.
 * 3. [x] Assign a file descriptor to the given map file.
 * 4. [ ] Allocate memory for a 2D char buffer.
 * 5. [ ] Read the map file into said buffer.
 */

int	main(int argc, char **argv)
{
	int		fd;
	char	**map_desc;
	char	*file_name;
	size_t	line_count;

	if (argc != 2)
		no_map_error(argv[0]);
	file_name = argv[1];
	validate_file_name(file_name);
	line_count = count_lines(file_name);
	fd = open_map_file(file_name);
	map_desc = prep_map_array(fd, line_count); 
	free_map_array(map_desc, line_count);
	close_and_handle_error(fd);
	return (0);
}
