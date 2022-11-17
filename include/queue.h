/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:37:37 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/17 08:43:26 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
/** 
 * @file queue.h
 * @brief Contains the functions used in the project.
 */

// ---------------------------------
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// ---------include_path ------------
# include "types_q.h"

t_queue		*new_queue(void);
void		qput(t_queue *queue, t_nodeq *new);
t_nodeq		*new_node(void *data);
t_nodeq		*qget(t_queue *queue);
void		free_queue(t_queue *queue);
t_nodeq		*qget_front(t_queue *queue);
t_nodeq		*q_n_get(t_queue *queue);
#endif /* !QUEEUE_H */