/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_q.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:55:06 by akharraz          #+#    #+#             */
/*   Updated: 2022/09/04 01:00:58 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
/**
 * @brief free node recursively
 * 
 * @param node head
 */
static void	free_nodes(t_nodeq *node)
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
void	free_queue(t_queue *queue)
{
	free_nodes(queue->head);
	free(queue);
}