/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:42:33 by onorridg          #+#    #+#             */
/*   Updated: 2022/11/08 16:22:02 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1

# define TRUE 1
# define FALSE 0

# define SPACE 0x12c0e3
# define WALL 0x1fab3d
# define COLLECTIBLE 0xfcad03
# define EXIT 0x00ff2a
# define PLAYER 0xd91c42

# define PIXELS 64

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

# include <mlx.h>

typedef struct s_list
{
	char			*line;
	int				len;	
}	t_list;

typedef struct s_map_info
{
	int	max_x;
	int	max_y;
	int	coins;
}	t_map_info;

t_list	get_next_line(int fd, char *str);
char	*ft_strjoin(char *s1, char *s2, int flag);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(const char *s);
int		ft_find_end_line(char *string);
char	*ft_free(char *string);

int		main(int ac, char **av);
int		check_border(char *line, int len, int flag);
int		check_cep(char **map, int i, int player, int y);
void	ft_exit(char **map, char *error);
int		get_fd(char *file_name);
void	map_clear(char **map);
char	*ft_itoa(int n);

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_data
{	
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**map;
	t_map_info	map_info;
	t_pos		player;
	int			coins;
	int			moves;
	int			left_right;
}	t_data;

void	so_long(t_map_info map_info, char **map);
void	inti_vars(t_map_info map_info, char **map, t_data *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	wall_img(t_data *vars, int x_pix, int y_pix);
void	bottom_img(t_data *vars, int x_pix, int y_pix);
void	coin_img(t_data *vars, int x_pix, int y_pix);
void	exit_img(t_data *vars, int x_pix, int y_pix);
void	user_img(t_data *vars, int x_pix, int y_pix);

void	right_move(t_data *vars);
void	up_move(t_data *vars);
void	down_move(t_data *vars);
void	left_move(t_data *vars);

void	help_print_map(t_data *vars, int *x_pix, int *y_pix, t_pos *xy);
void	help_move_player(t_data *vars, int com);

#endif