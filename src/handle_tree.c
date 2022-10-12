/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:28:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/02 08:48:41 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

	
static void free_onenode(t_node	*node)
{
	free(node->token.token);
	free(node);
}

int	sub_shell(t_vars	*vars, t_node *node)
{
	t_snode *temp;

	if (node->node_type != PR)
		return 0;
	if (node->token.type == LP)
	{
		push(vars->roots, new_snode(vars->root));
		vars->root = NULL;
	}
	if (node->token.type == RP)
	{
		vars->root->node_type = BLOCK;
		temp = pop(vars->roots);
		put_block(&temp->root, vars->root);
		vars->root = temp->root;
		free(temp);
	}
	return 1;
}

int	handle_token(char *token ,t_vars *vars)
{
	t_node 		*node;

	if (token == NULL)
		return -1;
	node = create_token(new_tnode(), token);
	if (node == NULL)
		return -1;
	if (!accepted(node))
		return printf("Minishell: syntax error near unexpected token '%s'\n",\
			 node->token.token), free_onenode(node), 0;
	free_pr(node);
	if (vars->root == NULL && node->node_type != OP && node->node_type != PR)
		return vars->root = node, 1;
	if (sub_shell(vars, node))
		return 1;
	if (handle_block(vars, node))
		return 1;
	if (handle_OP(vars, node))
		return 1;
	return 1;
}
