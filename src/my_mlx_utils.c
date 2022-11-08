/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:23:43 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/25 19:46:16 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	inti_vars(t_map_info map_info, char **map, t_data *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, map_info.max_x * PIXELS,
			map_info.max_y * PIXELS + PIXELS, "so_long");
	vars->img = mlx_new_image(vars->mlx, map_info.max_x * PIXELS,
			map_info.max_y * PIXELS + PIXELS);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	vars->map = map;
	vars->coins = map_info.coins;
	vars->map_info = map_info;
	vars->moves = 0;
	vars->left_right = 0;
}
