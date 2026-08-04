/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:16:20 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/04 18:23:31 by agoudet-         ###   ########.fr       */
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

void	no_map_error(char *prog_name);
void	validate_file_name(char *file_name);
int		open_map_file(char *map_file_name);
size_t	count_lines(char *map_file_name);
char	**prep_map_array(int fd, size_t num_lines);
void	free_map_array(char **map_array, size_t alloc_count);
void	close_and_handle_error(int fd);

#endif
