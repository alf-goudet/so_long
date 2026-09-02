/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:59:27 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/02 14:13:56 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	close_and_handle_error(int fd, t_game *game);

static void	calc_map_height(int temp_fd, t_game *game)
{
	char	*temp_line;

	while (1)
	{
		temp_line = get_next_line(temp_fd);
		if (temp_line == NULL)
		{
			if (ft_strncmp(strerror(errno), "Success", 8) != 0)
			{
				if (close(temp_fd) == -1)
					error_exit("close", game);
				else
					error_exit("get_next_line", game);
			}
			else if (game->map.height == 0)
				error_exit("Empty map file", game);
			break ;
		}
		game->map.height++;
		free(temp_line);
	}
}

static void	fill_grid(t_game *game, int fd)
{
	char			*newl;
	size_t			i;

	i = 0;
	game->map.grid = (char **)ft_calloc(game->map.height, sizeof(char *));
	if (game->map.grid == NULL)
		error_exit("malloc", game);
	while (i < game->map.height)
	{
		game->map.grid[i] = get_next_line(fd);
		if (game->map.grid[i] == NULL)
			error_exit("get_next_line", game);
		newl = ft_strchr(game->map.grid[i], '\n');
		*newl = '\0';
		i++;
	}
}

void	read_map(char *file, t_game *game)
{
	int		fd[2];
	size_t	i;

	fd[0] = open(file, O_RDWR);
	if (fd[0] == -1)
		error_exit(file, game);
	fd[1] = open(file, O_RDONLY);
	calc_map_height(fd[1], game);
	close_and_handle_error(fd[1], game);
	fill_grid(game, fd[0]);
	close_and_handle_error(fd[0], game);
	check_rectangular(game);
	check_walls(game);
	check_chars(game);
	i = 0;
	while (i < game->map.height)
	{	
		ft_printf("%s\n", game->map.grid[i]);
		i++;
	}
}

static void	close_and_handle_error(int fd, t_game *game)
{
	int	close_check;

	close_check = close(fd);
	if (close_check == -1)
		error_exit("close", game);
}
