/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:38:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/18 19:32:26 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

/**
 * @brief allocate to a new node
 * 
 * @param data to put into the new node
 * @return allocate adress of the new node
 */
t_nodeq	*new_node(void *data)
{
	t_nodeq	*node;

	node = (t_nodeq *)malloc(sizeof(t_nodeq));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/**
 * @brief allocate for queue structure
 * @param none
 * 
 * @return allocate address for queue structure
 */
t_queue	*new_queue(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->head = NULL;
	queue->tail = NULL;
	queue->size = 0;
	return (queue);
}

/**
 * @brief put to the front of the queue
 * 
 * @param queue 
 * @param new_node
 */
void	qput(t_queue *queue, t_nodeq *new)
{
	if (!(queue->head))
	{
		queue->head = new;
		queue->tail = new;
	}
	else
	{
		queue->head->prev = new;
		new->next = queue->head;
		queue->head = new;
	}
	queue->size += 1;
}

/**
 * @brief get from the back of the queue
 * 
 * @param queue
 * @return node that take form back of the queue
 */
t_nodeq	*qget(t_queue *queue)
{
	t_nodeq	*tail;

	if (queue->head == NULL)
		return (NULL);
	queue->size -= 1;
	tail = queue->tail;
	if (!(queue->size))
		return (queue->head = NULL, queue->tail = NULL, tail);
	queue->tail = queue->tail->prev;
	queue->tail->next = NULL;
	return (tail);
}

/**
 * @brief get from the front of the queue
 * 
 * @param queue
 * @return node that take form front of the queue
 */
t_nodeq	*qget_front(t_queue *queue)
{
	t_nodeq	*front;

	if (queue->head == NULL)
		return (NULL);
	queue->size -= 1;
	front = queue->head;
	queue->head = queue->head->next;
	return (front);
}
