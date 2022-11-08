/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:20:41 by onorridg          #+#    #+#             */
/*   Updated: 2022/11/07 16:31:01 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_move_player(t_data *vars, int com)
{	
	int		w;
	int		h;
	void	*img;

	if (com == 0 || com == 2 || com == 97 || com == 100)
		vars->left_right = com;
	img = mlx_xpm_file_to_image(vars->mlx, "./sprites/bottom.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, img,
		vars->player.x * PIXELS, vars->player.y * PIXELS);
	if (vars->left_right == 2 || vars->left_right == 100)
		img = mlx_xpm_file_to_image(vars->mlx, "./sprites/user_r.xpm", &w, &h);
	else if (vars->left_right == 0 || vars->left_right == 97)
		img = mlx_xpm_file_to_image(vars->mlx, "./sprites/user_l.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, img,
		vars->player.x * PIXELS, vars->player.y * PIXELS);
	if (vars->coins == 0 && vars->map[vars->player.y][vars->player.x] == 'E')
		vars->coins = -1;
}

void	help_print_map(t_data *vars, int *x_pix, int *y_pix, t_pos *xy)
{
	if (vars->map[xy->y][xy->x] == '1')
		wall_img(vars, *x_pix, *y_pix);
	else if (vars->map[xy->y][xy->x] == '0')
		bottom_img(vars, *x_pix, *y_pix);
	else if (vars->map[xy->y][xy->x] == 'C')
		coin_img(vars, *x_pix, *y_pix);
	else if (vars->map[xy->y][xy->x] == 'E')
		exit_img(vars, *x_pix, *y_pix);
	else if (vars->map[xy->y][xy->x] == 'P')
	{
		vars->player.x = xy->x;
		vars->player.y = xy->y;
		user_img(vars, *x_pix, *y_pix);
	}
	xy->x++;
	*x_pix += PIXELS;
}
