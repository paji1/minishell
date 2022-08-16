/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:00:52 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/08/16 02:02:53 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*dub_add(char *str, char *ad)
{
	char	*s;
	int		len;
	int		ad_len;

	if (!str || !ad)
		return NULL;
	len = ft_strlen(str);
	ad_len = ft_strlen(ad);
	s = malloc(11 + 1 + len + ad_len);
	*s = '\0';
	ft_strlcat(s, "\033[0;34m", 8);
	ft_strlcat(s, str, 8 + len);
	ft_strlcat(s, ad, 8 + len + ad_len);
	ft_strlcat(s, "\033[0m", 12 + len + ad_len);
	return s;
	
}

char	*getbasename(char *path)
{
	char *last_slash;
	char *str;

	str = path;
	last_slash = "\0";
	while (*str)
	{
		if (*str == '/')
			last_slash = str;
		str++;
	}
	if (!(*last_slash))
		return path;
	if  (!(*(last_slash + 1)))
		return last_slash;
	return last_slash  + 1;
}

void	getdir(char **base_name)
{
	char *buff;

	buff = malloc(1244);	
	if (!getcwd(buff, -1))
		return perror("getcwd failed") ;
	*base_name = dub_add(getbasename(buff), "-> ");
	free(buff);
}