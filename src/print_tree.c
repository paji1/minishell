/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:10:15 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/08 19:01:00 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void print_tree(t_node *root)
{
	if (root == NULL)
		return ;
	print_tree(root->left);
	print_tree(root->right);
	printf("{sds}%s\n", root->token.token);
}