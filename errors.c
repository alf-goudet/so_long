/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:04:13 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/03 14:11:58 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	no_map_error(char *prog_name)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd("Expected a .ber map file argument", STDERR_FILENO);
	ft_putstr_fd("Example: ", STDERR_FILENO);
	ft_putstr_fd(prog_name, STDERR_FILENO);
	ft_putendl_fd(" map.ber", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

