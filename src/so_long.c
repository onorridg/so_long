/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:57:12 by onorridg          #+#    #+#             */
/*   Updated: 2022/11/08 15:52:07 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	my_mlx_print_bottom(t_data *vars)
{	
	int		w;
	int		h;
	void	*img;
	int		i;

	i = 1;
	img = mlx_xpm_file_to_image(vars->mlx, "./sprites/bottom.xpm", &w, &h);
	while (i < vars->map_info.max_x)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img, i * PIXELS,
			vars->map_info.max_y * PIXELS);
		i++;
	}
}

static void	my_mlx_print_map(t_data *vars)
{	
	int		x_pix;
	int		y_pix;
	t_pos	xy;

	y_pix = 0;
	xy.y = 0;
	while (vars->map[xy.y])
	{	
		xy.x = 0;
		x_pix = 0;
		while (vars->map[xy.y][xy.x])
			help_print_map(vars, &x_pix, &y_pix, &xy);
		y_pix += PIXELS;
		xy.y += 1;
	}
}

void	my_mlx_move_player(t_data *vars, int com)
{
	void		*img;
	int			h;
	int			w;

	img = mlx_xpm_file_to_image(vars->mlx, "./sprites/bottom.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, img, vars->player.x * PIXELS,
		vars->player.y * PIXELS);
	if ((com == 2 || com == 100)
		&& vars->map[vars->player.y][vars->player.x + 1] != '1'
		&& (vars->map[vars->player.y][vars->player.x + 1] != 'E'
			|| vars->coins == 0))
		right_move(vars);
	else if ((com == 13 || com == 119)
		&& vars->map[vars->player.y - 1][vars->player.x] != '1'
		&& (vars->map[vars->player.y - 1][vars->player.x] != 'E'
			|| vars->coins == 0))
		up_move(vars);
	else if ((com == 1 || com == 115)
		&& vars->map[vars->player.y + 1][vars->player.x] != '1'
		&& (vars->map[vars->player.y + 1][vars->player.x] != 'E'
			|| vars->coins == 0))
		down_move(vars);
	else if ((com == 0|| com == 97)
		&& vars->map[vars->player.y][vars->player.x - 1] != '1'
		&& (vars->map[vars->player.y][vars->player.x - 1] != 'E'
			|| vars->coins == 0))
		left_move(vars);
	help_move_player(vars, com);
}

int	press_button(int keycode, t_data *vars)
{	
	char	*moves;

	if ((keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13) 
		|| (keycode == 97 || keycode == 115 || keycode == 100
		|| keycode == 119))
	{
		my_mlx_move_player(vars, keycode);
		moves = ft_itoa(vars->moves);
		my_mlx_print_bottom(vars);
		mlx_string_put(vars->mlx, vars->win, PIXELS + (PIXELS / 2),
			vars->map_info.max_y * PIXELS + (PIXELS / 2), PLAYER, moves);
		free(moves);
	}
	if (vars->coins == -1)
		keycode = 53;
	
	if (keycode == 53)
	{	
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		map_clear(vars->map);
		exit(0);
	}
	return (0);
}

int exit_button(t_data *vars){
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	map_clear(vars->map);
	exit(0);
}

void	so_long(t_map_info map_info, char **map)
{
	t_data	vars;
	void	*img;
	int		w;
	int		h;

	inti_vars(map_info, map, &vars);
	mlx_hook(vars.win, 2, 1L << 0, press_button, &vars);
	mlx_hook(vars.win, 17, 0, exit_button, &vars);
	my_mlx_print_map(&vars);
	img = mlx_xpm_file_to_image(vars.mlx, "./sprites/bottom.xpm", &w, &h);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 0,
		vars.map_info.max_y * PIXELS);
	mlx_put_image_to_window(vars.mlx, vars.win, img,
		PIXELS, vars.map_info.max_y * PIXELS);
	mlx_string_put(vars.mlx, vars.win, 2,
		vars.map_info.max_y * PIXELS + (PIXELS / 2), PLAYER, "Count:");
	my_mlx_print_bottom(&vars);
	mlx_loop(vars.mlx);
}
