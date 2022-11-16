/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 02:56:47 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/16 07:41:12 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int is_accepted(char *buff, int i)
{
	if (buff[i] != '*')
		return 0;
	if (i == 0 && !ft_isalnum(buff[i]))
		return 1;
	if (i == 0)
		return 0;
	if (!ft_isalnum(buff[i - 1]) && !buff[i + 1])
		return 1;
	if (!ft_isalnum(buff[i + 1]) && !ft_isalnum(buff[i - 1]))
		return 1;
	return 0;
}

static char *join_free(char *s1, char *s2)
{
	char *s;

	s = ft_strjoin(s1, s2);
	free(s1);
	return s;
}

char *get_files(void)
{
	DIR				*dir;
	struct dirent	*ddir;
	char			*str;

	dir = opendir(".");
	ddir = readdir(dir);
	str = ft_strdup("");
	while (ddir)
	{
		if (!ft_strcmp(ddir->d_name, ".") || !ft_strcmp(ddir->d_name, ".."))
		{
			ddir = readdir(dir);
			continue;;
		}
		str = join_free(str, ddir->d_name);
		str = join_free(str, " ");
		ddir = readdir(dir);
	}
	closedir(dir);
	return str;
}

static void expand_key(char **str, size_t start, size_t end, char *files)
{
	char *first;
	char *second;
	char *value;
	char *temp;

	if (end == start)
		return ;
	first = ft_substr(*str, 0, start);
	second = ft_strdup(*str + end);
	value = files;
	temp = ft_strjoin(first, value);
	free(first);
	first = ft_strjoin(temp, second);
	free(temp);
	free(second);
	free(*str);
	*str = first;
}

void expand_wildcard(char **buff)
{
	t_quote quote;
	char	*temp;
	char	*files;
	int		i;

	if (!*buff)
		return ;
	ft_bzero(&quote, sizeof(t_quote));
	i = -1;
	files = get_files();
	temp = *buff;
	while (temp[++i])
	{
		quote_handle(&quote, i, temp);
		if (is_accepted(temp, i) && !quote.in_quote)
		{
			if (temp[i + 1] && temp[i + 1] == '*')
				expand_key(buff, i, i + 1, "");
			expand_key(buff, i, i + 1, files);
			i--;
			temp = *buff;
		}
	}
	free(files);
}
