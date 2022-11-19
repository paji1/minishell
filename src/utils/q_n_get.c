/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_n_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:32:19 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/18 19:32:35 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_nodeq	*q_n_get(t_queue *queue)
{
	static t_nodeq	*tail;
	t_nodeq			*temp;

	if (tail == NULL)
		tail = queue->tail;
	temp = tail;
	tail = tail->prev;
	return (temp);
}
