/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:54:39 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/22 21:01:22 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H
# include <stdbool.h>

# ifdef __linux__
#  define ON_LINUX true
#  define ESC_KEY 65307
#  define W_KEY 119	
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
# elif __APPLE__
#  define ON_LINUX false
#  define ESC_KEY 53
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
# endif
#endif
