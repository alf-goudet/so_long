/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:48:36 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/05 21:51:34 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * 1. [x] Check if the number of arguments is 2. Otherwise ask user for a map.
 * 2. [x] Check that the given filename ends in a NUL-terminated .ber.
 * 3. [x] Assign a file descriptor to the given map file.
 * 4. [x] Allocate memory for a 2D char buffer.
 * 5. [x] Read the map file into said buffer.
 * 6. [ ] Verify that the given map is valid according to the subject.
 *
 * 		6.1. [x] Verify that there aren't any characters other than '1', '0',
 *			'P', 'C' and 'E'.
 *
 *		6.2. [ ] Verify that the edges are entirely made of walls (to prevent
 *			moving out of bounds).
 *
 *			6.2.1. [ ] The first and last lines should be made entirely of
 *				walls.
 *
 *			6.2.2. [ ] The lines between the first and the last must have a
 *				wall in their first and last characters.
 *
 *		6.3. [ ] Verify the existence of one 'P', one 'E' and at least one 'C'.
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
	close_and_handle_error(fd);
	validate_map(map_desc, line_count);
	free_map_array(map_desc, line_count);
	return (0);
}
