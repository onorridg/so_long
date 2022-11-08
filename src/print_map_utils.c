/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:33:48 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/25 18:55:16 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_img(t_data *vars, int x_pix, int y_pix)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, "./sprites/wall.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x_pix, y_pix);
}

void	bottom_img(t_data *vars, int x_pix, int y_pix)
{	
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, "./sprites/bottom.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x_pix, y_pix);
}

void	coin_img(t_data *vars, int x_pix, int y_pix)
{	
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, "./sprites/bottom.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x_pix, y_pix);
	img = mlx_xpm_file_to_image(vars->mlx, "./sprites/coin.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x_pix, y_pix);
}

void	exit_img(t_data *vars, int x_pix, int y_pix)
{	
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, "./sprites/exit.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x_pix, y_pix);
}

void	user_img(t_data *vars, int x_pix, int y_pix)
{	
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, "./sprites/bottom.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x_pix, y_pix);
	img = mlx_xpm_file_to_image(vars->mlx, "./sprites/user_l.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x_pix, y_pix);
}
