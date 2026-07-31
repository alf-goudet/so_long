/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:48:36 by agoudet-          #+#    #+#             */
/*   Updated: 2026/07/29 14:34:20 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
//	void	*win_ptr;

	ft_printf("Hello, so_long!\n");
	ft_printf("Establishing new MiniLibX connection: ");
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	ft_printf("Done!\n");
	ft_printf("Opening new Window:\n");
	mlx_ptr = mlx_new_window(mlx_ptr, 800, 800, "Test MiniLibX Window");
	if (mlx_ptr == NULL)
		return (1);
	while (1)
		mlx_loop(mlx_ptr);
	ft_printf("End of MiniLibX test\n");
	return (0);
}
