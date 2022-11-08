/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:13:29 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/17 11:13:56 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_free(char *string)
{
	if (string)
	{
		free(string);
		string = NULL;
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	int	len;
	int	i;

	len = ft_strlen((char *) src);
	i = 0;
	if (dstsize)
	{
		dstsize--;
		while (src[i] && dstsize--)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2, int flag)
{
	int		l_s1;
	int		l_s2;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	if (l_s1 == 0 && l_s2 == 0)
		return (0);
	new_str = (char *)malloc(sizeof(char) * (l_s1 + l_s2) + 1);
	if (new_str)
	{
		if (l_s1 != 0)
			ft_strlcpy(new_str, (char *) s1, l_s1 + 1);
		if (l_s2 != 0)
			ft_strlcpy(&new_str[l_s1], (char *) s2, l_s2 + 1);
	}
	if (flag == 1)
		ft_free(s1);
	return (new_str);
}

void	ft_bzero(void *s, size_t n)
{
	char	*s_ptr;

	s_ptr = (char *) s;
	while (n-- > 0)
		*s_ptr++ = '\0';
}
