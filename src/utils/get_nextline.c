/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nextline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:00:42 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/22 03:07:35 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strchr_n(const char *p, int c)
{
	int			i;

	i = 0;
	while (p[i] != (char )c && p[i])
		i++;
	if (!p[i])
		return (-1);
	return (i);
}

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*p;
	size_t	lens;
	size_t	lenf;

	if (!s1 || !s2)
		return (NULL);
	lens = ft_strlen(s2);
	lenf = ft_strlen(s1);
	p = (char *)malloc(lenf + lens + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, lenf + 1);
	ft_strlcpy(p + lenf, s2, lenf + lens + 1);
	if (!*p)
		return (free(p), NULL);
	if (*s1)
		free(s1);
	return (p);
}

static char	*readbuf(int fd, char *str)
{
	char	buff[BUFFER_SIZE + 1];
	int		n;

	*buff = 0;
	n = 1;
	if (!str)
		str = "";
	if (ft_strchr_n(str, '\n') != -1)
		return (str);
	while (ft_strchr_n(buff, '\n') == -1 && n)
	{	
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
			return (NULL);
		buff[n] = 0;
		if (*buff)
			str = ft_strjoin_free(str, buff);
	}
	if (!*str)
		return (NULL);
	return (str);
}

static char	*get_line(char **str)
{
	int		i;
	char	*s;
	char	*t;

	if (!*str)
		return (NULL);
	i = ft_strchr_n(*str, '\n');
	if (i == -1)
		return (NULL);
	if (!*(*str + i + 1))
		return (NULL);
	s = ft_strdup(*str + i + 1);
	t = *str;
	*str = malloc(i + 2);
	if (!*str)
		return (NULL);
	return (ft_strlcpy(*str, t, i + 2), free(t), s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*r;

	r = NULL;
	r = readbuf(fd, str);
	if (!r)
		return (NULL);
	return (str = get_line(&r), r);
}