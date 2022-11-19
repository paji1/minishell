/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:41:24 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/18 19:34:54 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief free node recursively
 * 
 * @param node head
 */
static void	free_nodes(t_snode *node)
{
	if (!node)
		return ;
	free_nodes(node->next);
	free(node);
}

/**
 * @brief call free_nodes and free queue
 * 
 * @param queue 
 */
void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->head && stack->head->root)
		free_tree(stack->head->root);
	free_nodes(stack->head);
	free(stack);
}
