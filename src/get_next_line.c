/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:38:28 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/25 19:58:45 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_support(char *string, char *save_str, char *buffer)
{
	if (save_str)
		string = ft_strjoin(save_str, buffer, 0);
	else if (string)
		string = ft_strjoin(string, buffer, 1);
	else
		string = ft_strjoin(buffer, "", 0);
	return (string);
}

int	ft_find_end_line(char *buffer)
{
	int	i;
	int	buffer_len;

	if (!buffer)
		return (0);
	i = 0;
	buffer_len = ft_strlen(buffer);
	while (i < buffer_len)
	{	
		if (buffer[i] == '\0' || buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-21);
}

char	*ft_get_final_string(char *string)
{
	int		i;
	int		string_len;
	char	*new_string;
	int		flag;

	string_len = 0;
	flag = 0;
	if (!string)
		return (0);
	while (string[string_len] != '\n' && string[string_len] != '\0')
		string_len++;
	if (string[string_len] == '\n')
		flag = 1;
	new_string = (char *)malloc(sizeof(char) * (string_len + flag + 1));
	if (!new_string)
		return (ft_free(string));
	i = -1;
	while (++i < string_len)
		new_string[i] = string[i];
	if (flag == 1)
		new_string[i++] = '\n';
	new_string[i] = '\0';
	ft_free(string);
	return (new_string);
}

char	*ft_get_line(char *buffer, char *string)
{	
	string = ft_support(string, 0, buffer);
	return (string);
}

t_list	get_next_line(int fd, char *str)
{	
	int			read_result;
	char		*buffer;
	int			flag;
	t_list		map;

	map.len = 0;
	map.line = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (map);
	while (1)
	{	
		ft_bzero(buffer, BUFFER_SIZE + 1);
		read_result = read(fd, buffer, BUFFER_SIZE);
		map.len += read_result;
		if ((read_result == -1 || read_result == 0) && !ft_get_line(0, 0))
			break ;
		str = ft_get_line(buffer, str);
		flag = ft_find_end_line(str);
		if (flag > -1)
			break ;
	}
	ft_free(buffer);
	map.line = ft_get_final_string(str);
	return (map);
}
