/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:16:20 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/25 14:34:28 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdio.h>				// for perror()
# include <fcntl.h>				// for open()
# include <unistd.h>			// for close(), read(), write()
# include <stdlib.h>			// for malloc(), free(), exit()
# include <string.h>			// for strerror()
# include <stdbool.h>			// for boolean true/false values
# include <errno.h>				// to use errno variable

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	char	*file_name;
	char	**map_desc;
	size_t	num_rows;
}			t_data;

void	validate_file_name(char *file_name);
int		open_map_file(char *map_file_name);
void	count_rows(t_data *data);
void	prep_map_array(t_data *data);
void	validate_map(t_data *data);
void	free_map_array(char **map_array, size_t alloc_count);
void	close_and_handle_error(t_data *data);

// Error handler functions
int		no_map_error(char *prog_name);
void	invalid_char_error(char curr_chr, t_data *data);
void	open_edges_error(t_data *data);
void	no_rect_map_error(t_data *data);
void	feature_requirements_error(size_t *elms, t_data *data);

// Other helper functions
void	check_horiz_edges(t_data *data, size_t row_idx);
void	check_vert_edges(t_data *data, size_t row_idx);
void	count_map_elements(size_t *elms, t_data *data);

#endif
