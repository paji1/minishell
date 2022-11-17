/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_q.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:55:06 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/14 05:33:46 by tel-mouh         ###   ########.fr       */
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
	if (temp->type == DELIMITER && temp->fd_HERDOC != -1)
		close(temp->fd_HERDOC);
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