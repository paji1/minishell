/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:00:52 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/09 12:19:36 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief allocate memory for prompt and return address
 * 
 * @param str base_name
 * @param ad post prompt
 * @return allocated memory for char * base_name
 */
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
	ft_strlcat(s, "\033[0;91m", 8);
	ft_strlcat(s, str, 8 + len);
	ft_strlcat(s, ad, 8 + len + ad_len);
	ft_strlcat(s, "\033[0m", 12 + len + ad_len);
	return s;
	
}

/**
 * @brief get basename for directory
 * 
 * @param path of the directory
 * @return char* addresses when basename is started
 */
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

/**
 * @brief get the path and allocated prompt string
 * with color and optional postfix characters
 * @param base_name address of pointer base_name
 * @return size_t size of prompt
 */
size_t	getdir(char **base_name)
{
	char *buff;

	buff = malloc(PATH_MAX);	
	if (!getcwd(buff, -1))
		return free(buff), *base_name = dub_add(getbasename("."), "-> ") , -1;
	*base_name = dub_add(getbasename(buff), "-> ");
	free(buff);
	return (ft_strlen(*base_name));
}