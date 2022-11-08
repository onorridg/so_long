/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:22:31 by onorridg          #+#    #+#             */
/*   Updated: 2022/11/07 16:54:59 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_clear(char **map)
{	
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	if (map)
		free(map);
}

int	get_fd(char *file_name)
{	
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		ft_exit(0, "Your file map is so shiet :-|\n");
	return (fd);
}

void	ft_exit(char **map, char *error)
{
	if (map)
		map_clear(map);
	write(1, "[!] Error\n", ft_strlen("[!] Error\n"));
	write(1, error, ft_strlen(error));
	exit(1);
}

int	check_border(char *line, int len, int flag)
{
	int	i;
	int	boarder;
	int	wtf;

	i = 0;
	wtf = 0;
	boarder = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == '1')
			boarder += 1;
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P'
			&& line[i] != 'C' && line[i] != 'E')
			wtf = -1;
		i++;
	}
	if (wtf == -1)
		return (1);
	if (flag == 0 && (boarder != i || i != len))
		return (1);
	else if (flag == 1 && (line[0] != '1' || line[i - 1] != '1' || i != len))
		return (1);
	return (0);
}

int	check_cep(char **map, int i, int player, int y)
{	
	int	collectible;
	int	exit;

	collectible = 0;
	exit = 0;
	player = 0;
	y = 0;
	while (map[y])
	{	
		i = 0;
		while (map[y][i])
		{
			if (map[y][i] == 'C')
				collectible += 1;
			else if (map[y][i] == 'E')
				exit += 1;
			else if (map[y][i] == 'P')
				player += 1;
			i++;
		}
		y++;
	}
	if (player != 1 || collectible == 0 || exit == 0)
		return (1);
	return (0);
}
