/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:46:25 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/16 01:48:35 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	case_so(t_node *node, t_nodeq *q)
{
	if (q->data->token.type >= REDIRECT_SO && q->data->token.type <= HERDOC)
		return (0);
	if (q->next->data->token.type == REDIRECT_SI)
		return (0);
	close(node->file_out);
	if (q->next->data->token.type == REDIRECT_SO)
		node->file_out = open(q->data->token.token, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (q->next->data->token.type == APPEND)
		node->file_out = open(q->data->token.token, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (node->file_out == -1)
		return (-1);
	return (0);
}

static int	case_si(t_node *node, t_nodeq *q)
{
	static int lock;

	if ((q->data->token.type >= REDIRECT_SO && q->data->token.type <= HERDOC))
		return (0);
	if (q->next->data->token.type == REDIRECT_SO || q->next->data->token.type == APPEND)
		return (0);
	close(node->file_in); 
	if (access(q->data->token.token, F_OK) == -1)
		return check_permission(q->data->token.token);
	if (access(q->data->token.token, R_OK) == -1)
		return check_permission(q->data->token.token);
	if (q->next->data->token.type == REDIRECT_SI)
		node->file_in = open(q->data->token.token, 0);
	return (3);
}

char *get_name(int fd)
{
	char *s;
	char *stemp;
	struct stat buf;
	DIR  *dir;
	struct dirent *ddir;

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
	return stemp;
}

static int	case_herd(t_node *node, t_nodeq *q)
{
	char *file_name;

	file_name = get_name(q->data->token.fd_HERDOC);
	close(q->data->token.fd_HERDOC);
	q->data->token.fd_HERDOC = open(file_name, O_RDONLY, 0666);
	free(file_name);
	close(node->file_in);
	node->file_in = q->data->token.fd_HERDOC;
	return (1);
}

int	handle_redirection(t_node *node)
{
	t_nodeq	*q;
	int		i;
	int		out;

	if (!node->token.redir)
		return 0;
	i = -1;
	while (++i < node->token.redir->size)
	{
		q = q_n_get(node->token.redir);
		case_so(node, q);
		if (case_si(node, q) == -1)
			return -1;
		if (q->data->token.type == DELIMITER)
			case_herd(node, q);
	}
	return (0);
}
