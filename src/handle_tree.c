/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:28:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/16 00:38:27 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int handle_OP(t_vars *vars, t_node *node)
{
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
		return printf("parse error, 	invalid token\n"), 0;
	if (vars->root == NULL)
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
		(*root)->right = new;
		return ;
	}
	put_block(&(*root)->right, new);
}