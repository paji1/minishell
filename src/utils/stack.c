/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:09:05 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/04 20:53:03 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_stack *new_element(t_node *data)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return NULL;
	new->next = NULL;
	new->node = data;
	return new;
}

void	push(t_stack **stack, t_stack *new)
{
	if (new == NULL)
		return ;
	new->next = (*stack);
	(*stack) = new;
}

t_node *pop(t_stack **stack)
{
	t_stack *pop_element;
	t_node *node;

	if ((*stack) == NULL)
		return NULL;
	pop_element = (*stack);
	(*stack) = (*stack)->next;
	node = pop_element->node;
	free(pop_element);
	return node;
}

void free_stack(t_stack **stack)
{
	if ((*stack) == NULL)
		return ;
	free_stack(&(*stack)->next);
	free(*stack);
	(*stack) = NULL;
}