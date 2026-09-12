/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:37:52 by agoudet-          #+#    #+#             */
/*   Updated: 2026/09/12 20:35:10 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// so_long.h - Core header file for the so_long project

#ifndef SO_LONG_H
# define SO_LONG_H

/* ************************************************************************** */
/* MACRO DEFINITIONS                                                          */
/* ************************************************************************** */

# define TILE_SIZE 64 // Size in pixels of every tile to render

// 1. Event and mask values for mlx_hook(), as in /usr/include/X11/X.h

# define DESTROY_NOTIFY 17 		// Value of DestroyNotify event macro
# define NO_EVENT_MASK 0L		// Value of NoEventMask macro

// 2. Keycode definitions for this project (depending on running OS)

// 2.1. Linux keycodes
# ifdef __linux__
#  define ON_LINUX true		// To run mlx_destroy_notify (on Linux only)
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100

// 2.2. macOS keycodes
# elif __APPLE__
#  define ON_LINUX false	// To skip mlx_destroy_display on macOS (segfault)
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
# endif

/* ************************************************************************** */
/* HEADER INCLUSIONS                                                          */
/* ************************************************************************** */

# include <stdbool.h> 	// for explicit true/false boolean values
# include <stdlib.h> 	// for exit()
# include <fcntl.h> 	// for open()
# include <stdio.h> 	// for perror()
# include <string.h> 	// for strerror()
# include <unistd.h> 	// for read() (in get_next_line) and close()
# include <errno.h> 	// to use variable errno (in strerror())
# include <X11/X.h> 	// to access event and mask macros
# include "libft.h" 	// to use my libft, ft_printf and get_next_line
# include "mlx.h" 		// to use MiniLibX

/* ************************************************************************** */
/* STRUCTURE DEFINITIONS                                                      */
/* ************************************************************************** */

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
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}			t_game;

/* ************************************************************************** */
/* FUNCTION PROTOTYPES                                                        */
/* ************************************************************************** */

void	error_exit(char *msg, t_game *game);
void	read_map(char *file, t_game *game);
void	check_rectangular(t_game *game);
void	check_walls(t_game *game);
void	check_chars(t_game *game);
void	check_paths(t_game *game);
char	**copy_and_fill_grid(t_game *game);
void	free_map(char **grid, size_t row_allocs);
void	flood_fill(char **map, size_t x, size_t y);
void	load_images(t_game *game);
void	render_map(t_game *game);
int		close_game(void *param);
int		key_press(int keycode, void *param);
void	move_player(t_game *g, int keycode, int dx, int dy);

#endif
