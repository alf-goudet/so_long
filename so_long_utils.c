/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:46:05 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/07 16:52:32 by agoudet-         ###   ########.fr       */
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

size_t	count_lines(char *map_file_name)
{
	size_t	line_count;
	char	*temp_line;
	int		temp_fd;

	temp_fd = open_map_file(map_file_name);
	line_count = 0;
	while (1)
	{
		temp_line = get_next_line(temp_fd);
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
		line_count++;
		free(temp_line);
	}
	close_and_handle_error(temp_fd);
	return (line_count);
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

void	close_and_handle_error(int fd)
{
	int	close_checker;

	close_checker = close(fd);
	if (close_checker == -1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		perror("close");
		exit(EXIT_FAILURE);
	}
}

// NOTE: In the count_map_elements function:
// - *elms[0]: Counter for player's staring position(s)
// - *elms[1]: Counter for map's exit position(s)
// - *elms[2]: Counter for collectibles
void	count_map_elements(size_t *elms, char **map_desc, size_t num_rows)
{
	size_t	row_idx;
	size_t	col_idx;
	char	curr_chr;

	row_idx = 0;
	while (row_idx < num_rows)
	{
		col_idx = 0;
		curr_chr = map_desc[row_idx][col_idx];
		while (curr_chr != '\n' && curr_chr != '\0')
		{
			if (curr_chr == 'P')
				elms[0]++;
			else if (curr_chr == 'E')
				elms[1]++;
			else if (curr_chr == 'C')
				elms[2]++;
			col_idx++;
			curr_chr = map_desc[row_idx][col_idx];
		}
		row_idx++;
	}
}
