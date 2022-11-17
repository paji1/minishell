/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:10:31 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/16 09:55:28 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*create_file_name(void)
{
	static int	l;
	char		*str;
	char		*joinstr;

	str = ft_itoa(l);
	if (!str)
		return (NULL);
	joinstr = ft_strjoin("/tmp/minishell-", str);
	if (!joinstr)
		return (free(str), NULL);
	free(str);
	return (l++, joinstr);
}

int	create_file(void)
{
	char	*name;
	int		fd;

	name = create_file_name();
	if (!name)
		return (-1);
	fd = open(name, O_RDWR | O_EXCL | O_CREAT, 0600);
	if (errno == EEXIST)
		return (errno = 0, free(name), create_file());
	if (fd == -1)
		return (free(name), -1);
	free(name);
	return (fd);
}

int	handle_herdoc(t_node *new)
{
	static t_node	*node;
	char			*line;
	char			*tmp_token;

	line = NULL;
	if (new->token.type == HERDOC)
		return (node = new, 0);
	if (new->token.type != FILED)
		return (0);
	if (!node)
		return (1);
	ignore_signal_herdoc();
	new->token.type = DELIMITER;
	new->token.fd_HERDOC = create_file();
	tmp_token = ft_strjoin(new->token.token, "\n");
	expand_string_toquote(&tmp_token, (t_env *) NULL);
	while (!line || ft_strcmp(line, tmp_token))
	{
		if (line)
			free(line);
		line = get_next_line(0);
		if (!line)
			return (free(tmp_token), 1);
		if (line && ft_strcmp(line, tmp_token))
			write(new->token.fd_HERDOC, line, ft_strlen(line));
	}
	if (line)
		free(line);
	free(tmp_token);
	handle_signal();
	return (0);
}
