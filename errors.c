/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:04:13 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/25 14:27:23 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	no_map_error(char *prog_name)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd("Expected a .ber map file argument", STDERR_FILENO);
	ft_putstr_fd("Example: ", STDERR_FILENO);
	ft_putstr_fd(prog_name, STDERR_FILENO);
	ft_putendl_fd(" map.ber", STDERR_FILENO);
	return (EXIT_FAILURE);
}

void	invalid_char_error(char curr_chr, t_data *data)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putstr_fd("Found invalid character in map grid: ", STDERR_FILENO);
	ft_putchar_fd(curr_chr, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	ft_putendl_fd("Only characters allowed: 0, 1, C, E, P", STDERR_FILENO);
	free_map_array(data->map_desc, data->num_rows);
	exit(EXIT_FAILURE);
}

void	open_edges_error(t_data *data)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putstr_fd("Map not entirely ", STDERR_FILENO);
	ft_putendl_fd("covered in walls ('1')", STDERR_FILENO);
	free_map_array(data->map_desc, data->num_rows);
	exit(EXIT_FAILURE);	
}

void	no_rect_map_error(t_data *data)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putstr_fd("Given map must be rectangular", STDERR_FILENO);
	ft_putendl_fd(" (All lines equally long)", STDERR_FILENO);
	free_map_array(data->map_desc, data->num_rows);
	exit(EXIT_FAILURE);
}

// NOTE: In feature_requirements_error:
// - nsuf: Flag variable to decide whether to print error messages due to
//	insufficient minimum elements or due to excessive start/exit elements.
void	feature_requirements_error(size_t *elms, t_data *data)
{
	if (elms[0] == 0 || elms[1] == 0 || elms[2] == 0)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd("Not enough map elements for game", STDERR_FILENO);
		ft_putendl_fd("Required:", STDERR_FILENO);
		ft_putendl_fd("- 1 starting position ('P')", STDERR_FILENO);
		ft_putendl_fd("- 1 exit ('E')", STDERR_FILENO);
		ft_putendl_fd("- 1 or more collectibles ('C')", STDERR_FILENO);
		free(elms);
		free_map_array(data->map_desc, data->num_rows);
		exit(EXIT_FAILURE);
	}
	else if (elms[0] != 1 || elms[1] != 1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd("Too many start/exit elements on map", STDERR_FILENO);
		ft_putstr_fd("Only one start ('P') ", STDERR_FILENO);
		ft_putendl_fd("and one exit ('E') is allowed", STDERR_FILENO);
		free(elms);
		free_map_array(data->map_desc, data->num_rows);
		exit(EXIT_FAILURE);
	}
}
