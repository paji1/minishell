/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:36:46 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/18 20:39:25 by akharraz         ###   ########.fr       */
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

void	above_root(t_node **root, t_node *new)
{
	new->left = (*root);
	new->right = NULL;
	*root = new;
}
