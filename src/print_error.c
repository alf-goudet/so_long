/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:39:59 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/26 20:41:53 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error_and_exit(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}
