/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:37:52 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/02 14:13:29 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h> // for exit()
# include <fcntl.h> // for open()
# include <stdio.h> // for perror()
# include <string.h> // for strerror()
# include <unistd.h> // for read() (in get_next_line) and close()
# include <errno.h> // to use variable errno (in strerror())
# include "libft.h" // to use my libft and ft_printf()
# include "mlx.h" // to use MiniLibX

typedef struct s_map
{
	char	**grid;
	size_t	width;
	size_t	height;
	size_t	collects;
	size_t	exit;
	size_t	player_pos;
	size_t	player_start_x;
	size_t	player_start_y;
}			t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	size_t	move_count;
	void	**img_ptrs;
}			t_game;

void	error_exit(char *msg, t_game *game);
void	read_map(char *file, t_game *game);
void	check_rectangular(t_game *game);
void	check_walls(t_game *game);
void	check_chars(t_game *game);

#endif
