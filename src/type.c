/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:22:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/02 09:11:05 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_type(char *token)
{
	static int last_token;

	if (token == NULL)
		return last_token = 0, -1;
		
	if (!ft_strcmp(token , "||"))
		return last_token = OR , OR;
	else if (!ft_strcmp(token , "&&"))
		return last_token = AND , AND;
	else if (!ft_strcmp(token , "|"))
		return last_token = PIP , PIP;
	else if (!ft_strcmp(token, ">"))
		return last_token = REDIRECT_SO , REDIRECT_SO;
	else if (!ft_strcmp(token, "<"))
		return last_token = REDIRECT_SI , REDIRECT_SI;
	else if (!ft_strcmp(token, ">>"))
		return last_token = APPEND , APPEND;
	else if (!ft_strcmp(token, "<<"))
		return last_token = HERDOC , HERDOC;
	else if (!ft_strcmp(token , ")"))
		return last_token = RP , RP;
	else if (!ft_strcmp(token , "("))
		return last_token = LP , LP;
	else
	{
		if (!last_token || (last_token >= AND && last_token <= LP))
			return last_token = CMD, CMD;
		else if (last_token >= REDIRECT_SO && last_token <= HERDOC)
			return last_token = FILED , FILED;
		else if (last_token == CMD && token[0] == '-')
			return last_token = OPTIONS , OPTIONS;
		else
			return last_token = ARG , ARG;
	}
}

int block_op(int type)
{
	if (type == CMD || type == FILED || type == ARG || type == OPTIONS \
		|| type == -1)
		return BLOCK;
	else if (type == LP || type == RP)
		return PR;
	else
		return OP;
}

int expected(t_node *new, t_node *node)
{
	if (node->node_type == BLOCK)
		return (new->node_type == BLOCK || new->node_type == OP ||\
			new->token.type == RP);
	else if (node->token.type == LP)
		return new->node_type != OP && new->token.type != RP;
	else if (node->token.type == RP)
		return new->node_type != BLOCK  && new->token.type != LP;
	else if (node->token.type >= AND && node->token.type <= PIP && \
		(new->token.type >= REDIRECT_SO && new->token.type <= HERDOC))
		return (1);
	else if (node->node_type == OP)
		return (new->node_type == BLOCK || new->token.type == LP);
	return 0;
}




int handle_pranteses(t_node *new)
{
	static int state;

	if (new == NULL)
	{
		if (!state)
			return state = 0, 0;
		else
			return state = 0, 1;
	}
	if (new->node_type != PR)
		return 0;
	if (!state && new->token.type == RP)
		return 1;
	if (new->token.type == LP)
		return state++, 0;
	else if (new->token.type == RP)
		return state--, 0;
	return 0;
}



int accepted(t_node *new)
{
	static t_node	*node;
	int				cond;

	if (handle_pranteses(new))
		return  node= NULL, 0;
	if (new == NULL)
		return cond = node->node_type != OP, \
			 node = NULL, cond;
	if (node == NULL)
	{
		node = new;
		cond = !(node->token.type >= AND && node->token.type <= PIP) \
				&& node->token.type != RP;
		if (!cond)
			node = NULL;
		return cond;
	}
	if (!expected(new, node))
		return handle_pranteses(NULL),  node = NULL, 0;
	return node = new, 1;
}
