/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 16:42:00 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/25 14:32:36 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	map_is_rectangular(t_data *data);

static void	validate_map_chars(t_data *data);

static void	validate_map_edges(t_data *data);

static void	validate_minimum_elements(t_data *data);

void	validate_map(t_data *data)
{
	if (!map_is_rectangular(data))
		no_rect_map_error(data);
	validate_map_chars(data);
	validate_map_edges(data);
	validate_minimum_elements(data);
}

static bool	map_is_rectangular(t_data *data)
{
	char const	*first_row = data->map_desc[0];
	char		*next_row;
	size_t		target_len;
	size_t		row_idx;
	size_t		row_len;

	target_len = ft_strlen(first_row) - 1;
	row_idx = 1;
	while (row_idx < data->num_rows)
	{
		next_row = data->map_desc[row_idx];
		row_len = ft_strlen(next_row) - 1;
		if (row_len != target_len)
			return (false);
		row_idx++;
	}
	return (true);
}

static void	validate_map_chars(t_data *data)
{
	size_t	row_idx;
	size_t	col_idx;
	char	curr_chr;

	row_idx = 0;
	while (row_idx < data->num_rows)
	{
		col_idx = 0;
		curr_chr = data->map_desc[row_idx][col_idx];
		while (curr_chr != '\n' && curr_chr != '\0')
		{
			if (curr_chr == '1' || curr_chr == '0' || curr_chr == 'P'
				|| curr_chr == 'E' || curr_chr == 'C')
			{
				col_idx++;
				curr_chr = data->map_desc[row_idx][col_idx];
			}
			else
				invalid_char_error(curr_chr, data);
		}
		row_idx++;
	}
}

static void	validate_map_edges(t_data *data)
{	
	size_t	row_idx;

	row_idx = 0;
	while (row_idx < data->num_rows)
	{
		if (row_idx == 0 || row_idx == data->num_rows - 1)
			check_horiz_edges(data, row_idx);
		else
			check_vert_edges(data, row_idx);
		row_idx++;
	}
}

static void	validate_minimum_elements(t_data *data)
{
	size_t			*elements;
	size_t const	start = 0;
	size_t const	exit_pos = 1;
	size_t const	collectibles = 2;

	elements = (size_t *)malloc(3 * sizeof(size_t));
	if (elements == NULL)
	{
		perror("malloc failure");
		free_map_array(data->map_desc, data->num_rows);
		exit(EXIT_FAILURE);
	}
	elements[start] = 0;
	elements[exit_pos] = 0;
	elements[collectibles] = 0;
	count_map_elements(elements, data);
	feature_requirements_error(elements, data);
	free(elements);
}
