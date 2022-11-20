/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:46:25 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/19 05:05:27 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(int fd)
{
	char			*s;
	char			*stemp;
	struct stat		buf;
	DIR				*dir;
	struct dirent	*ddir;

	s = NULL;
	dir = opendir("/tmp");
	ddir = readdir(dir);
	fstat(fd, &buf);
	while ((void *)ddir != NULL)
	{
		if (ddir->d_ino == buf.st_ino)
		{
			s = strdup(ddir->d_name);
			break ;
		}
		ddir = readdir(dir);
	}
	closedir(dir);
	stemp = ft_strjoin("/tmp/", s);
	free(s);
	return (stemp);
}

void	expand_herdoc(int *fd, t_env *env)
{
	char	*s;
	char	*file_name;
	int		new_fd;

	file_name = get_name(*fd);
	close(*fd);
	*fd = open(file_name, O_RDONLY, 0666);
	new_fd = create_file();
	s = get_next_line(*fd);
	while (s)
	{
		expand_str(&s, env);
		ft_putstr_fd(s, new_fd);
		free(s);
		s = get_next_line(*fd);
	}
	free(file_name);
	close(*fd);
	*fd = new_fd;
}

int	handle_redirection(t_node *node, t_env *env)
{
	t_nodeq	*q;
	int		i;

	if (!node->token.redir)
		return (0);
	i = -1;
	while (++i < node->token.redir->size)
	{
		q = q_n_get(node->token.redir);
		case_so(node, q);
		if (case_si(node, q) == -1)
			return (-1);
		if (q->data->token.type == DELIMITER)
			case_herd(node, q, env);
	}
	return (0);
}
