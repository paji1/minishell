/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_first_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:05:25 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/05 01:08:14 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void preorder(t_node *node)
{
	if (node == NULL)
		return ;
	printf("%d level = %d \n", node->data, node->level);
	preorder(node->left);
	preorder(node->right);
}

void iter_print(t_node *node)
{
	t_stack *stack;
	t_node *current;

	stack = NULL;
	push(&stack, new_element(node));
	while (stack)
	{
		current = pop(&stack);
		if  (current->right != NULL)
			push(&stack, new_element(current->right));
		if  (current->left != NULL)
			push(&stack, new_element(current->left));
		printf("%d\n", current->data);
	}
	free_stack(&stack);
}