/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_q.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:55:06 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/17 08:45:57 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "queue.h"
/**
 * @brief free node recursively
 * 
 * @param node head
 */
static void	free_nodes(t_nodeq *node)
{
	t_token	*temp;

	if (!node)
		return ;
	free_nodes(node->next);
	temp = &node->data->token;
	if (temp->type == DELIMITER && temp->fd_herdoc != -1)
		close(temp->fd_herdoc);
	free(temp->token);
	free(node->data);
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