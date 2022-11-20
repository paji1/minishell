/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:12:21 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/13 22:13:56 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_block(t_vars *vars, t_node *node)
{
	if (node->node_type != BLOCK)
		return (0);
	return (put_block(&vars->root, node), 1);
}

static int	put_arg_option(t_node **root, t_node *new)
{
	if (new->token.type == ARG || new->token.type == OPTIONS)
	{
		if ((*root)->token.args_q == NULL)
			(*root)->token.args_q = new_queue();
		qput((*root)->token.args_q, new_node(new));
		handle_herdoc(new);
		return (1);
	}
	return (0);
}

static int	put_arg_as_cmd(t_node **root, t_node *new)
{
	if (new->token.type == ARG && !*((*root)->token.token))
	{
		free((*root)->token.token);
		(*root)->token.token = new->token.token;
		free(new);
		return (1);
	}
	return (0);
}

static int	put_file(t_node **root, t_node *new)
{
	if (new->token.type == FILED)
	{
		qput((*root)->token.redir, new_node(new));
		handle_herdoc(new);
		return (1);
	}
	return (0);
}

void	put_block(t_node **root, t_node *new)
{
	if (*root == NULL)
	{
		*root = new;
		return ;
	}
	if ((*root)->right == NULL || is_sub(*root))
	{
		if (put_file(root, new))
			return ;
		if (put_arg_as_cmd(root, new))
			return ;
		if (put_arg_option(root, new))
			return ;
		(*root)->right = new;
		return ;
	}
	put_block(&(*root)->right, new);
}
