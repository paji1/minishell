/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/05 01:46:19 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


//                   10
//                 /    \                         /
//               -1      17
//              /  \    /  \                      /
//            -2    3  15  18
//                   \                            /
//                    4
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

int main(void)
{
	t_node *node;
	
	node = NULL;
	insert(&node, new_node(10));
	// insert(&node, new_node(1));
	insert(&node, new_node(-1));
	insert(&node, new_node(17));
	insert(&node, new_node(15));
	insert(&node, new_node(3));
	insert(&node, new_node(18));
	insert(&node, new_node(4));
	insert(&node, new_node(-2));
	// printf("%p\n", stack);
	brefirstrev(node);
	free_tree(&node);
	// 	printf("%d\n", contain(&node, i));
	return 0;
}
