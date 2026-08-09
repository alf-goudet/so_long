/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 20:00:49 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/05 21:56:24 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**prep_map_array(int fd, size_t num_lines)
{
	char	**map_array;
	size_t	i;

	map_array = (char **)malloc((num_lines + 1) * sizeof(char *));
	if (map_array == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < num_lines)
	{
		map_array[i] = get_next_line(fd);
		if (map_array[i] == NULL)
		{
			perror("get_next_line");
			free_map_array(map_array, i);
			close_and_handle_error(fd);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	map_array[i] = NULL;
	return (map_array);
}
