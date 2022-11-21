/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirection_cases.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 05:04:53 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/21 08:37:51 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	case_so(t_node *node, t_nodeq *q)
{
	int	temp_fd;

	if (q->data->token.type >= REDIRECT_SO && q->data->token.type <= HERDOC)
		return (0);
	if (q->next->data->token.type == REDIRECT_SI)
		return (0);
	temp_fd = node->file_out;
	if (q->next->data->token.type == REDIRECT_SO)
			node->file_out = open(q->data->token.token, \
		O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (q->next->data->token.type == APPEND)
		node->file_out = open(q->data->token.token, \
			O_CREAT | O_RDWR | O_APPEND, 0644);
	if (node->file_out == -1)
		return (-1);
	close(temp_fd);
	return (0);
}

int	case_si(t_node *node, t_nodeq *q)
{
	int	temp_fd;

	if ((q->data->token.type >= REDIRECT_SO && q->data->token.type <= HERDOC))
		return (0);
	if (q->next->data->token.type == REDIRECT_SO || \
		q->next->data->token.type == APPEND)
		return (0);
	if (access(q->data->token.token, F_OK) == -1)
		return (check_permission(q->data->token.token));
	if (access(q->data->token.token, R_OK) == -1)
		return (check_permission(q->data->token.token));
	temp_fd = node->file_in;
	if (q->next->data->token.type == REDIRECT_SI)
		node->file_in = open(q->data->token.token, 0);
	close(temp_fd);
	return (3);
}

int	case_herd(t_node *node, t_nodeq *q, t_env *env)
{
	char	*file_name;

	if (q->data->token.token[0] != '\'' && q->data->token.token[0] != '\"')
		expand_herdoc(&q->data->token.fd_herdoc, env);
	file_name = get_name(q->data->token.fd_herdoc);
	close(q->data->token.fd_herdoc);
	q->data->token.fd_herdoc = open(file_name, O_RDONLY, 0666);
	free(file_name);
	node->file_in = q->data->token.fd_herdoc;
	return (1);
}
