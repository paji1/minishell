/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:10:31 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/15 13:25:14 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
char	*g_name;

static char	*create_file_name(void)
{
	static int	l;
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
	int		fd;

	g_name = create_file_name();
	if (!g_name)
		return -1;
	fd = open(g_name, O_WRONLY | O_EXCL | O_CREAT, 0600);
	if (errno == EEXIST)
		return errno = 0, free(g_name), create_file();
	if (fd == -1)
		return free(g_name), -1;
	// free(g_name);
	return fd;
}

int handle_herdoc(t_node *new)
{
	static t_node	*node;
	char			*line;
	char			*tmp_token;

	line = NULL;
	if (new->token.type == HERDOC)
		return node = new, 0;
	if (new->token.type != FILED)
		return 0;
	if (!node)
		return 1;
	ignore_signal_herdoc();
	new->token.type = DELIMITER;
	new->token.fd_HERDOC = create_file();
	tmp_token = ft_strjoin(new->token.token, "\n");
	while (!line || ft_strcmp(line, tmp_token))
	{
		if (line)
			free(line);
		line = get_next_line(0);
		if (!line)
			return free(tmp_token), 1;
		if (line)
			write(new->token.fd_HERDOC, line, ft_strlen(line));
		if (ft_strcmp(line, tmp_token))
			write(new->token.fd_HERDOC, "\n", 1);
	}
	if (line)
		free(line);
	free(tmp_token);
	handle_signal();
	close(new->token.fd_HERDOC);
	// printf("{%s}\n", g_name);
	new->token.fd_HERDOC = open(g_name, O_RDONLY, 0666);
	// printf("{%d}\n", new->token.fd_HERDOC);
	return 0;
}