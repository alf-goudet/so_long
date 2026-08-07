/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 16:42:00 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/07 20:55:28 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	map_is_rectangular(char **map_desc, size_t num_rows);

static void	validate_map_chars(char **map_desc, size_t num_rows);

static void	validate_map_edges(char **map_desc, size_t num_rows);

static void	validate_minimum_elements(char **map_desc, size_t num_rows);

void	validate_map(char **map_desc, size_t num_rows)
{
	if (!map_is_rectangular(map_desc, num_rows))
		no_rect_map_error(map_desc, num_rows);
	validate_map_chars(map_desc, num_rows);
	validate_map_edges(map_desc, num_rows);
	validate_minimum_elements(map_desc, num_rows);
}

static bool	map_is_rectangular(char **map_desc, size_t num_rows)
{
	char const	*first_row = map_desc[0];
	char		*next_row;
	size_t		target_len;
	size_t		row_idx;
	size_t		row_len;

	target_len = ft_strlen(first_row) - 1;
	row_idx = 1;
	while (row_idx < num_rows)
	{
		next_row = map_desc[row_idx];
		row_len = ft_strlen(next_row) - 1;
		if (row_len != target_len)
			return (false);
		row_idx++;
	}
	return (true);
}

static void	validate_map_chars(char **map_desc, size_t num_rows)
{
	size_t	row_idx;
	size_t	col_idx;
	char	curr_chr;

	row_idx = 0;
	while (row_idx < num_rows)
	{
		col_idx = 0;
		curr_chr = map_desc[row_idx][col_idx];
		while (curr_chr != '\n' && curr_chr != '\0')
		{
			if (curr_chr == '1' || curr_chr == '0' || curr_chr == 'P'
				|| curr_chr == 'E' || curr_chr == 'C')
			{
				col_idx++;
				curr_chr = map_desc[row_idx][col_idx];
			}
			else
				invalid_char_error(curr_chr, map_desc, num_rows);
		}
		row_idx++;
	}
}

static void	validate_map_edges(char **map_desc, size_t num_rows)
{	
	size_t	row_idx;

	row_idx = 0;
	while (row_idx < num_rows)
	{
		if (row_idx == 0 || row_idx == num_rows - 1)
			check_horiz_edges(map_desc, row_idx, num_rows);
		else
			check_vert_edges(map_desc, row_idx, num_rows);
		row_idx++;
	}
}

static void	validate_minimum_elements(char **map_desc, size_t num_rows)
{
	size_t			*elements;
	size_t const	start = 0;
	size_t const	exit_pos = 1;
	size_t const	collectibles = 2;

	elements = (size_t *)malloc(3 * sizeof(size_t));
	if (elements == NULL)
	{
		perror("malloc failure");
		free_map_array(map_desc, num_rows);
		exit(EXIT_FAILURE);
	}
	elements[start] = 0;
	elements[exit_pos] = 0;
	elements[collectibles] = 0;
	count_map_elements(elements, map_desc, num_rows);
	feature_requirements_error(elements, map_desc, num_rows);
	free(elements);
}
