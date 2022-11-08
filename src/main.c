/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:54:53 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/26 13:12:14 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_coins(char **map, t_map_info *map_info)
{
	int	y;
	int	i;

	y = 0;
	while (map[y])
	{
		i = 0;
		while (map[y][i])
		{
			if (map[y][i] == 'C')
				map_info->coins += 1;
			i++;
		}
		y++;
	}
}

static char	**write_map(int fd, int y, t_map_info *map_info)
{	
	t_list	tmp;
	int		i;
	char	**map;

	i = 0;
	map_info->coins = 0;
	map = malloc(sizeof(char *) * (y + 1));
	if (!map)
		ft_exit(0, "Greedy malloc\n");
	tmp = get_next_line(fd, NULL);
	while (tmp.line)
	{	
		map[i++] = tmp.line;
		tmp = get_next_line(fd, NULL);
	}
	map[i] = NULL;
	if (i != y)
		ft_exit(map, "Greedy malloc\n");
	count_coins(map, map_info);
	return (map);
}

static t_map_info	get_map_info(int fd)
{
	t_map_info	map_info;
	t_list		tmp;

	tmp = get_next_line(fd, NULL);
	map_info.max_x = tmp.len;
	map_info.max_y = 0;
	if (!tmp.line)
		ft_exit(0, "Your file map is so shit :-|\n");
	while (tmp.line)
	{	
		map_info.max_y += 1;
		free(tmp.line);
		tmp = get_next_line(fd, NULL);
	}
	if (close(fd) != 0)
		ft_exit(0, "I can't close the file\n");
	map_info.max_x -= 1;
	return (map_info);
}

static void	parser(char *file_map)
{	
	t_map_info	map_info;
	char		**map;
	int			i;

	i = 0;
	map_info = get_map_info(get_fd(file_map));
	map = write_map(get_fd(file_map), map_info.max_y, &map_info);
	if (check_border(map[i++], map_info.max_x, 0) == 1)
		ft_exit(map, "Your map is so shit :-|\n");
	while (i < map_info.max_y - 1)
	{	
		if (check_border(map[i++], map_info.max_x, 1) == 1)
			ft_exit(map, "Your map is so shit :-|\n");
	}
	if (check_border(map[i], map_info.max_x, 0) == 1)
		ft_exit(map, "Your map is so shit :-|\n");
	if (check_cep(map, 0, 0, 0) == 1)
		ft_exit(map, "Your map is so shit :-|\n");
	so_long(map_info, map);
}

int	main(int ac, char **av)
{
	if (ac > 2)
		ft_exit(0, "WTF, Dude ? Why are there so many arguments ?\n");
	else if (ac < 2)
		ft_exit(0, "Where's the money(args), Lebowski ?\n");
	else
		parser(av[1]);
	return (0);
}
