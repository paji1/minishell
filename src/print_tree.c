/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:10:15 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/03 18:33:03 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void print_tree(t_node *root,t_vars *vars)
{
	if (root == NULL)
		return ;
	printf("--------{%s}------{%d}\n", root->token.token, root->node_type);
	if (root->token.redir)
	{
		while (root->token.redir->head)
		{
			printf("%s   ",qget(root->token.redir)->data->token.token);
		}
		printf("\n");
	}
	print_tree(root->left, vars);
	if (!ft_strcmp("&&", root->token.token))
		sleep(2);
	print_tree(root->right, vars);
	if (!ft_strcmp("|", root->token.token))
		printf("status right %s\n", root->right->token.token);
	
	// if (root->node_type == OP)
	// {
	// if (root->token.redir)
	// {
	// 	t_node *temp = (root->token.redir->head->data);
	// 	printf("%s\n", temp->token.token);
	// }
		// printf("left == %s type=%d\n", root->left->token.token, root->left->token.type);
		// printf("right == %s type=%d\n", root->right->token.token, root->right->token.type);
	// }
}