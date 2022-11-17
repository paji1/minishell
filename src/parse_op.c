/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:10:39 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/17 08:45:57 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_sub(t_node *node)
{
	if (node->node_type == BLOCK && node->token.type <= PIP \
		&& node->token.type >= AND)
		return (1);
	return (0);
}

int	handle_op(t_vars *vars, t_node *node)
{
	if (node->node_type != OP)
		return (0);
	if (node->token.type >= REDIRECT_SO && node->token.type <= HERDOC)
		return (put_redir(&vars->root, node), 1);
	if (vars->root->node_type == BLOCK && node->node_type == OP)
		return (node->left = vars->root, vars->root = node, 1);
	if (node->token.type == OR || node->token.type == AND)
		return (above_root(&vars->root, node), 1);
	if (node->token.type <= vars->root->token.type)
		return (above_root(&vars->root, node), 1);
	else
		return (nested(&vars->root, node), 1);
	return (0);
}

void	above_root(t_node **root, t_node *new)
{
	new->left = (*root);
	new->right = NULL;
	*root = new;
}

void	nested(t_node **root, t_node *new)
{
	if ((*root)->token.type > new->token.type)
	{
		new->left = (*root);
		new->right = NULL;
		(*root) = new;
		return ;
	}
	nested(&(*root)->right, new);
}

static void	*create_empty_node(t_node **root)
{
	*root = new_tnode();
	(*root)->node_type = BLOCK;
	(*root)->token.type = CMD;
	(*root)->token.token = ft_strdup("");
	if (!(*root)->token.token)
		return (NULL);
	(*root)->token.redir = new_queue();
	(*root)->token.fd_herdoc = -1;
	(*root)->file_in = 0;
	(*root)->file_out = 1;
	(*root)->token.args_q = NULL;
	(*root)->token.exit_status = -1;
	accepted((*root));
	return ((void *)1);
}

static void	put_redir_to_queue(t_node *node, t_node *new)
{
	if (node->token.redir == NULL)
		node->token.redir = new_queue();
	qput(node->token.redir, new_node(new));
	handle_herdoc(new);
}

void	put_redir(t_node **root, t_node *new)
{
	if (*root == NULL)
	{	
		if (!create_empty_node(root))
			return ;
		qput((*root)->token.redir, new_node(new));
		handle_herdoc(new);
		return ;
	}
	if ((*root)->right == NULL || is_sub(*root))
	{
		if ((*root)->node_type == OP && !is_sub(*root))
		{
			create_empty_node(&(*root)->right);
			put_redir_to_queue((*root)->right, new);
			return ;
		}
		put_redir_to_queue((*root), new);
		return ;
	}
	put_redir(&(*root)->right, new);
}
