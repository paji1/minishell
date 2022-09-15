/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:22:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/15 22:58:40 by tel-mouh         ###   ########.fr       */
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
	else
	{
		if (!last_token || last_token == PIP || last_token == AND || last_token == OR )
			return last_token = CMD, CMD;
		else if (last_token == REDIRECT_SO || last_token == REDIRECT_SI || last_token == APPEND || last_token == HERDOC)
			return last_token = FILED , FILED;
		else if (last_token == CMD && token[0] == '-')
			return last_token = OPTIONS , OPTIONS;
		else
			return last_token = ARG , ARG;
	}
	// return -1;
}

int block_op(char *token)
{
	int type;

	type = get_type(token);
	if (type == CMD || type == FILED || type == ARG|| type == OPTIONS )
		return BLOCK;
	else
		return OP;
}



int expected(t_node *new, int type)
{
	if (type == BLOCK)
		return (new->node_type == BLOCK || new->node_type == OP);
	else if (type == OP)
		return (\
		new->node_type == BLOCK || (new->node_type == OP \
		&& new->token.type != AND  && new->token.type != OR\
		));
	return 0;
}

int accepted(t_node *new)
{
	static t_node	*node;
	int				cond;

	if (new == NULL)
		return cond = !(node->node_type == OP), node = NULL, cond;
	if (node == NULL)
		return node = new, !(node->token.type == AND || node->token.type == OR || node->token.type == PIP);
	if (!expected(new, node->node_type))
		return 0;
	return node = new, 1;
}


