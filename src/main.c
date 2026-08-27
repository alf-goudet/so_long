/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:22:35 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/26 20:50:02 by agoudet-         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error_and_exit("Missing map argument (.ber)");
	}
	if (!file_ext_is_ber(argv[1]))
	{
		print_error_and_exit("Map argument doesn't end in .ber");
	}
	return (0);
}
