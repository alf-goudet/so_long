/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:16:20 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/07 20:40:56 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <stdio.h>				// for perror()
# include <fcntl.h>				// for open()
# include <unistd.h>			// for close(), read(), write()
# include <stdlib.h>			// for malloc(), free(), exit()
# include <string.h>			// for strerror()
# include <stdbool.h>			// for boolean true/false values
# include <errno.h>				// to use errno variable

void	validate_file_name(char *file_name);
int		open_map_file(char *map_file_name);
size_t	count_lines(char *map_file_name);
char	**prep_map_array(int fd, size_t num_lines);
void	validate_map(char **map_desc, size_t num_rows);
void	free_map_array(char **map_array, size_t alloc_count);
void	close_and_handle_error(int fd);

// Error handler functions
void	no_map_error(char *prog_name);
void	invalid_char_error(char curr_chr, char **map_desc, size_t num_rows);
void	open_edges_error(char **map_desc, size_t num_rows);
void	no_rect_map_error(char **map_desc, size_t num_rows);
void	feature_requirements_error(size_t *e, char **map_desc, size_t num_rows);

// Other helper functions
void	check_horiz_edges(char **map_desc, size_t row_idx, size_t n_rows);
void	check_vert_edges(char **map_desc, size_t row_idx, size_t n_rows);
void	count_map_elements(size_t *elms, char **map_desc, size_t num_rows);

#endif
