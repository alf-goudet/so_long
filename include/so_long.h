/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:37:52 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/29 14:31:44 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h> // for exit()
# include "libft.h" // to use my libft and ft_printf()
# include "mlx.h" // to use MiniLibX

typedef struct s_map
{
	char		**grid;
	size_t		width;
	size_t		height;
	size_t		collects;
	size_t		exit;
	size_t		player_pos;
}				t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	size_t	move_count;
	void	**img_ptrs;
}			t_game;

void	error_exit(char *msg, t_game *game);

#endif
