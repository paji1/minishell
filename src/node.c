/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:22:43 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/16 03:43:19 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node *create_token(t_node *new, char *token)
{
	if (!new)
		return NULL;
	new->token.type = get_type(token);
	new->node_type = block_op(token);
	new->token.token = token;
	new->token.redir = NULL;
	new->token.args_q = NULL;
	return new;
}

/**
 * @brief create a new token and get value from t_token
 * 
 * @return t_node* new allocated node to put in tree
 */
t_node *new_tnode(void)
{
	t_node *new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return NULL;
	new->left = NULL;
	new->right = NULL;
	return new;
}