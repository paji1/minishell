/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:44:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/07 05:38:36 by tel-mouh         ###   ########.fr       */
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


int main(void)
{
	t_node *node;
	
	node = NULL;
	// insert(&node, new_node(1));
	node = new_node(addition, TOKEN);
	node->left = new_node(multiply, TOKEN);
	node->left->left = new_node(8, NUM);
	node->left->right = new_node(3, NUM);
	node->right = new_node(addition, TOKEN);
	// node->right->right = new_node(1, NUM);
	node->right->left = new_node(multiply, TOKEN);
	node->right->left->left = new_node(-4, NUM);
	node->right->left->right = new_node(8, NUM);
	// insert(&node, new_node(-1, NUM));
	// insert(&node, new_node(17, NUM));
	// insert(&node, new_node(15, NUM));
	// insert(&node, new_node(3, NUM));
	// insert(&node, new_node(18, NUM));
	// insert(&node, new_node(4, NUM));
	// insert(&node, new_node(-2, NUM));
	preorder(node);
	printf("%d\n", node->data);
	free_tree(&node);
	// 	printf("%d\n", contain(&node, i));
	return 0;
}
