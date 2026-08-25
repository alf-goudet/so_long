/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 20:00:49 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/25 15:03:18 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	prep_map_array(t_data *data)
{
	size_t	i;

	data->map_desc = (char **)malloc((data->num_rows + 1) * sizeof(char *));
	if (data->map_desc == NULL)
	{
		perror("malloc");
		close_and_handle_error(data);
		free_map_array(data->map_desc, data->num_rows);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < data->num_rows)
	{
		data->map_desc[i] = get_next_line(data->fd);
		if (data->map_desc[i] == NULL)
		{
			perror("get_next_line");
			close_and_handle_error(data);
			free_map_array(data->map_desc, i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	data->map_desc[i] = NULL;
}
