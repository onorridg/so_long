/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:04:20 by onorridg          #+#    #+#             */
/*   Updated: 2022/11/07 16:28:20 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_move(t_data *vars)
{
	vars->moves += 1;
	if (vars->map[vars->player.y][vars->player.x + 1] == 'C')
		vars->coins -= 1;
	vars->map[vars->player.y][vars->player.x] = '0';
	vars->player.x += 1;
	if (vars->coins == 0 && vars->map[vars->player.y][vars->player.x] == 'E')
		vars->coins = -1;
	vars->map[vars->player.y][vars->player.x] = 'P';
}

void	up_move(t_data *vars)
{
	vars->moves += 1;
	if (vars->map[vars->player.y - 1][vars->player.x] == 'C')
		vars->coins -= 1;
	vars->map[vars->player.y][vars->player.x] = '0';
	vars->player.y -= 1;
	if (vars->coins == 0 && vars->map[vars->player.y][vars->player.x] == 'E')
		vars->coins = -1;
	vars->map[vars->player.y][vars->player.x] = 'P';
}

void	down_move(t_data *vars)
{
	vars->moves += 1;
	if (vars->map[vars->player.y + 1][vars->player.x] == 'C')
		vars->coins -= 1;
	vars->map[vars->player.y][vars->player.x] = '0';
	vars->player.y += 1;
	if (vars->coins == 0 && vars->map[vars->player.y][vars->player.x] == 'E')
		vars->coins = -1;
	vars->map[vars->player.y][vars->player.x] = 'P';
}

void	left_move(t_data *vars)
{
	vars->moves += 1;
	if (vars->map[vars->player.y][vars->player.x - 1] == 'C')
		vars->coins -= 1;
	vars->map[vars->player.y][vars->player.x] = '0';
	vars->player.x -= 1;
	if (vars->coins == 0 && vars->map[vars->player.y][vars->player.x] == 'E')
		vars->coins = -1;
	vars->map[vars->player.y][vars->player.x] = 'P';
}
