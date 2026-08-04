/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:46:05 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/04 20:39:22 by agoudet-         ###   ########.fr       */
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
