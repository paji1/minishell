/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:37:17 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/25 02:59:45 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief allocate to a new node
 * 
 * @param data to put into the new node
 * @return allocate adress of the new node
 */
t_snode	*new_snode(t_node *data)
{
	t_snode	*node;

	node = (t_snode *)malloc(sizeof(t_snode));
	if (!node)
		return (NULL);
	node->root = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/**
 * @brief allocate for stack structure
 * @param none
 * 
 * @return allocate address for stack structure
 */
t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

/**
 * @brief put to the front of the stack
 * 
 * @param stack 
 * @param new_node
 */
void	push(t_stack *stack, t_snode *new)
{
	if (!(stack->head))
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		stack->head->prev = new;
		new->next = stack->head;
		stack->head = new;
	}
	stack->size += 1;
}

/**
 * @brief get from the back of the stack
 * 
 * @param stack
 * @return node that take form back of the stack
 */
t_snode	*sget(t_stack *stack)
{
	t_snode	*tail;

	if (stack->head == NULL)
		return (NULL);
	stack->size -= 1;
	tail = stack->tail;
	if (!(stack->size))
		return (stack->head = NULL, stack->tail = NULL, tail);
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	return (tail);
}

/**
 * @brief get from the front of the stack
 * 
 * @param stack
 * @return node that take form front of the stack
 */
t_snode	*pop(t_stack *stack)
{
	t_snode	*front;

	if (stack->head == NULL)
		return (NULL);
	stack->size -= 1;
	front = stack->head;
	stack->head = stack->head->next;
	return (front);
}
