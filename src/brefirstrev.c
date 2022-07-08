/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brefirstrev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 03:40:36 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/07 04:54:46 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void brefirstrev(t_node *node)
{
	t_stack *stack;
	t_stack *stack_b;
	t_node *current;

	stack = NULL;
	stack_b = NULL;
	push(&stack, new_element(node));
	while (stack)
	{
		while (stack)
		{
			push(&stack_b, new_element(stack->node));
			printf("%d\n", stack->node->data);
			pop(&stack);
		}
		while(stack_b)
		{
			current = pop(&stack_b);
			if  (current->right != NULL)
				push(&stack, new_element(current->right));
			if  (current->left != NULL)
				push(&stack, new_element(current->left));
			
		}
	}
	free_stack(&stack);
	free_stack(&stack_b);
}