/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:10:31 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/22 02:19:32 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*create_file_name(void)
{
	static char	l;
	char		*str;
	char		*joinstr;

	str = ft_itoa(l);
	if (!str)
		return NULL;
	joinstr = ft_strjoin("/tmp/minishell-",str);
	if (!joinstr)
		return free(str), NULL;
	free(str);
	return l++, joinstr;
}

static int	create_file(void)
{
	char	*name;
	int		fd;

	name = create_file_name();
	if (!name)
		return -1;
	fd = open(name, O_RDWR | O_CREAT, 0600);
	if (fd == -1)
		return free(name), -1;
	free(name);
	return fd;
}

int handle_herdoc(t_node *new)
{
	static t_node	*node;
	char			*line;

	line = NULL;
	if (new->token.type == HERDOC)
		return node = new, 0;
	if (!node)
		return 1;
	new->token.type = DELIMITER;
	new->token.fd_HERDOC = create_file();
	while (!line || ft_strcmp(line, new->token.token))
	{
		line = readline(NULL);
		if (line)
			write(new->token.fd_HERDOC, line, ft_strlen(line));
		free(line);
		if (ft_strcmp(line, new->token.token))
			write(new->token.fd_HERDOC, "\n", 1);
	}
	return 0;
}