/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:28:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/22 00:12:38 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int handle_OP(t_vars *vars, t_node *node)
{
	if(node->token.type >= REDIRECT_SO && node->token.type <= HERDOC)
		return put_redir(&vars->root, node), 1;
	if (vars->root->node_type == BLOCK && node->node_type == OP)
		return node->left = vars->root,vars->root = node , 1;
	if (node->token.type == OR || node->token.type == AND)
		return above_root(&vars->root, node), 1;
	if (node->token.type <= vars->root->token.type)
		return above_root(&vars->root, node), 1;
	else
		return nested(&vars->root, node), 1;
	return 0;
}

int	handle_block(t_vars *vars, t_node *node)
{
	if (node->node_type != BLOCK)
		return 0;
	return put_block(&vars->root, node), 1;
}

int	handle_token(char *token ,t_vars *vars)
{
	t_node 		*node;

	if (token == NULL)
		return -1;
	node = create_token(new_tnode(), token);
	if (node == NULL)
		return -1;
	if (accepted(node) == 0)
		return printf("Minishell: syntax error near unexpected token '%s'\n",\
			 node->token.token), 0;
	if (vars->root == NULL && node->node_type != OP)
		return vars->root = node, 1;
	if (handle_block(vars, node))
		return 1;
	if (handle_OP(vars, node))
		return 1;
	return 1;
}

void	above_root(t_node **root, t_node *new)
{
	new->left = (*root);
	new->right = NULL;
	*root = new;
}

void	nested(t_node **root, t_node *new)
{
	if ((*root)->right->right == NULL)
	{
		if ((*root)->token.type <= new->token.type)
		{
			new->left = (*root)->right;
			new->right = NULL;
			(*root)->right = new;
		}
		return ;
	}
	nested(&(*root)->right, new);
}


void	put_block(t_node **root, t_node *new)
{
	if (*root == NULL)
	{
		*root = new; 
		return ;
	}
	if ((*root)->right == NULL)
	{
		if (new->token.type == FILED)
		{
			qput((*root)->token.redir, new_node(new));
			handle_herdoc(new);
			return	;
		}	
		if (new->token.type == ARG || new->token.type == OPTIONS)
		{
			if ((*root)->token.args_q == NULL)
				(*root)->token.args_q = new_queue();
			qput((*root)->token.args_q, new_node(new));
			handle_herdoc(new);
			return	;
		}	
		(*root)->right = new;
		return ;
	}
	put_block(&(*root)->right, new);
}

void	put_redir(t_node **root, t_node *new)
{
	if (*root == NULL)
	{	
		*root = new_tnode();
		(*root)->node_type = BLOCK;
		(*root)->token.type = FILED;
		(*root)->token.token = ft_strdup("");
		(*root)->token.redir = new_queue();
		qput((*root)->token.redir, new_node(new));
		handle_herdoc(new);
		return ;
	}
	if ((*root)->right == NULL)
	{
		if ((*root)->token.redir == NULL)
			(*root)->token.redir = new_queue();
		qput((*root)->token.redir, new_node(new));
		handle_herdoc(new);
		return ;
	}
	put_redir(&(*root)->right, new);
}
