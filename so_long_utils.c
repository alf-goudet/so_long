/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:46:05 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/25 14:56:35 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map_file(char *map_file_name)
{
	int		fd;
	
	fd = open(map_file_name, O_RDWR);
	if (fd == -1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	count_rows(t_data *data)
{
	char	*temp_line;

	data->fd = open_map_file(data->file_name);
	data->num_rows = 0;
	while (1)
	{
		temp_line = get_next_line(data->fd);
		if (temp_line == NULL)
		{
			if (ft_strncmp(strerror(errno), "Success", 8) == 0)
				break ;
			else
			{
				perror("get_next_line");
				exit(EXIT_FAILURE);
			}
		}
		data->num_rows++;
		free(temp_line);
	}
}

void	free_map_array(char **map_array, size_t alloc_count)
{
	size_t	i;

	i = 0;
	while (i < alloc_count)
	{
		free(map_array[i]);
		i++;
	}
	free(map_array);
}

void	close_and_handle_error(t_data *data)
{
	int	close_checker;

	close_checker = close(data->fd);
	if (close_checker == -1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		perror("close");
		free_map_array(data->map_desc, data->num_rows);
		exit(EXIT_FAILURE);
	}
}

// NOTE: In the count_map_elements function:
// - elms[0]: Counter for player's staring position(s)
// - elms[1]: Counter for map's exit position(s)
// - elms[2]: Counter for collectibles
void	count_map_elements(size_t *elms, t_data *data)
{
	size_t	row_idx;
	size_t	col_idx;
	char	curr_chr;

	row_idx = 0;
	while (row_idx < data->num_rows)
	{
		col_idx = 0;
		curr_chr = data->map_desc[row_idx][col_idx];
		while (curr_chr != '\n' && curr_chr != '\0')
		{
			if (curr_chr == 'P')
				elms[0]++;
			else if (curr_chr == 'E')
				elms[1]++;
			else if (curr_chr == 'C')
				elms[2]++;
			col_idx++;
			curr_chr = data->map_desc[row_idx][col_idx];
		}
		row_idx++;
	}
}
