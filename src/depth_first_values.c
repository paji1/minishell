/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_first_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:05:25 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/08 20:18:52 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int operation(int x, int op, int y)
{
	if (op == multiply)
		return x * y;
	else if (op == division)
		return x / y;
	else if (op == subtraction)
		return x - y;
	else if (op == addition)
		return x + y;
	return 0;
}

void preorder(t_node *node)
{
	if (node == NULL)
		return ;
	preorder(node->left);
	preorder(node->right);
	if (node->right && node->left)
	{
		node->data = operation(node->left->data, node->data, node->right->data);
		node->left->data = 0;
		node->right->data = 0;
		
	}
	// printf("%d \n", node->data);
	if (node->type == TOKEN)
		node->type = NUM;
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
