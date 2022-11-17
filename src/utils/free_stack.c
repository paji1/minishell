/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:41:24 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/01 12:58:02 by tel-mouh         ###   ########.fr       */
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