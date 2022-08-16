/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:32:40 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/08/16 02:18:13 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	nested(t_node **node, int token, int right)
{
	t_node *temp;

	temp = (*node)->right;
	(*node)->right = new_node(token, TOKEN);
	(*node)->right->left = temp;
	(*node)->right->right = new_node(right , NUM);
}

void	new_head(t_node **node, char token, int num_right)
{
	t_node *temp;

	temp = new_node(token, TOKEN);
	temp->right = new_node(num_right, NUM);
	temp->left = (*node);
	*node = temp;
}