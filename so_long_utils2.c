/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 15:12:59 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/06 15:19:56 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_horiz_edges(char **map_desc, size_t row_idx, size_t n_rows)
{
	size_t	col_idx;
	char	curr_chr;

	col_idx = 0;
	curr_chr = map_desc[row_idx][col_idx];
	while (curr_chr != '\n' && curr_chr != '\0')
	{
		if (curr_chr != '1')
			open_edges_error(map_desc, n_rows);
		col_idx++;	
		curr_chr = map_desc[row_idx][col_idx];
	}
}

void	check_vert_edges(char **map_desc, size_t row_idx, size_t n_rows)
{	
	size_t	col_idx;
	size_t	row_len;
	char	curr_chr;

	row_len = ft_strlen(map_desc[row_idx]) - 1;
	col_idx = 0;
	curr_chr = map_desc[row_idx][col_idx];
	while (curr_chr != '\0')
	{
		if ((col_idx == 0 || col_idx == row_len - 1) && curr_chr != '1')
			open_edges_error(map_desc, n_rows);
		col_idx++;
		curr_chr = map_desc[row_idx][col_idx];
	}
}
