/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:14:07 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/03 18:01:38 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	file_ext_is_ber(char *file_name)
{
	char	*file_ext;

	file_ext = ft_strrchr(file_name, '.');
	if (ft_strncmp(file_ext, ".ber", 5) == 0)
		return (true);
	else
		return (false);
}

void	validate_file_name(char *file_name)
{
	if (!file_ext_is_ber(file_name))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putstr_fd("Invalid map format ", STDERR_FILENO);
		ft_putendl_fd("(must be .ber)", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
