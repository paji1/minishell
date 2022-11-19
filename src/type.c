/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:22:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/19 04:54:52 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	block_type(int *last_token, char *token)
{
	if (!(*last_token) || ((*last_token) >= AND && (*last_token) <= LP))
		return ((*last_token) = CMD, CMD);
	else if ((*last_token) >= REDIRECT_SO && (*last_token) <= HERDOC)
		return ((*last_token) = FILED, FILED);
	else if ((*last_token) == CMD && token[0] == '-')
		return ((*last_token) = OPTIONS, OPTIONS);
	else
		return ((*last_token) = ARG, ARG);
}

int	get_type(char *token)
{
	static int	last_token;

	if (token == NULL)
		return (last_token = 0, -1);
	if (!ft_strcmp(token, "||"))
		return (last_token = OR, OR);
	else if (!ft_strcmp(token, "&&"))
		return (last_token = AND, AND);
	else if (!ft_strcmp(token, "|"))
		return (last_token = PIP, PIP);
	else if (!ft_strcmp(token, ">"))
		return (last_token = REDIRECT_SO, REDIRECT_SO);
	else if (!ft_strcmp(token, "<"))
		return (last_token = REDIRECT_SI, REDIRECT_SI);
	else if (!ft_strcmp(token, ">>"))
		return (last_token = APPEND, APPEND);
	else if (!ft_strcmp(token, "<<"))
		return (last_token = HERDOC, HERDOC);
	else if (!ft_strcmp(token, ")"))
		return (last_token = RP, RP);
	else if (!ft_strcmp(token, "("))
		return (last_token = LP, LP);
	else
		return (block_type(&last_token, token));
}

int	block_op(int type)
{
	if (type == CMD || type == FILED || type == ARG || type == OPTIONS \
		|| type == -1)
		return (BLOCK);
	else if (type == LP || type == RP)
		return (PR);
	else
		return (OP);
}

int	expected(t_node *new, t_node *node)
{
	if (node->node_type == BLOCK)
		return (new->node_type == BLOCK || new->node_type == OP || \
			new->token.type == RP);
	else if (node->token.type == LP)
		return (new->node_type != OP && new->token.type != RP);
	else if (node->token.type == RP)
		return (new->node_type != BLOCK && new->token.type != LP);
	else if (node->token.type >= AND && node->token.type <= PIP && \
		(new->token.type >= REDIRECT_SO && new->token.type <= HERDOC))
		return (1);
	else if (node->node_type == OP)
		return (new->node_type == BLOCK || new->token.type == LP);
	return (0);
}

int	accepted(t_node *new)
{
	static t_node	*node;
	int				cond;

	if (handle_pranteses(new))
		return (node = NULL, 0);
	if (new == NULL)
	{
		if (!node)
			return (0);
		return (cond = node->node_type != OP, \
			node = NULL, cond);
	}
	if (node == NULL)
	{
		node = new;
	cond = !(node->token.type >= AND && node->token.type <= PIP) \
			&& node->token.type != RP;
		if (!cond)
			node = NULL;
		return (cond);
	}
	if (!expected(new, node))
		return (handle_pranteses(NULL), node = NULL, 0);
	if (handle_empty_cmd(new))
		return (1);
	return (node = new, 1);
}
