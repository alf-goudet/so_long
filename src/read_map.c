/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:59:27 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/31 19:07:58 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**get_lines(int fd, t_game *game)
{
	char	**lines;
	size_t	*i;
	
	i = &(game->map.height);
	while (1)
	{
		lines[*i] = get_next_line(fd);
		if (lines[*i] == NULL)
		{
			if (ft_strncmp(strerror(errno), "Success", 8) == 0)
				break ;
			else
				error_exit("get_next_line", game);
		}
		(*i)++;
	}
	return (lines);
}

static void	fill_grid(t_game *game, char **lines)
{
	char			***grid;
	size_t			*width;
	size_t const	height = game->map.height;
	size_t			i;

	i = 0;
	grid = &(game->map.grid);
	width = &(game->map.width);
	while (i < height)
	{
		*width = ft_strlen(lines[i]);
		*grid[i] = (char *)malloc(*width * sizeof(char));
		if (*grid[i] == NULL)
			error_exit("malloc", game);
		ft_memcpy(*grid[i], lines[i], *width - 1);
		*grid[*width] = '\0';
		i++;
	}
}

void	read_map(char *file, t_game *game)
{
	int		fd;
	int		close_check;
	char	**lines;
	size_t	i;

	fd = open(file, O_RDWR);
	if (fd == -1)
		error_exit("open", game);
	lines = get_lines(fd, game);
	close_check = close(fd);
	if (close_check == -1)
		error_exit("close", game);
	game->map.grid = (char **)malloc((game->map.height) * sizeof(char *));
	if (game->map.grid == NULL)
		error_exit("malloc", game);
	fill_grid(game, lines);
	i = 0;
	while (i < game->map.height)
	{	
		ft_printf("%s\n", game->map.grid[i]);
		i++;
	}
}
