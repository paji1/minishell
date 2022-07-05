/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:11:33 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/04 18:28:14 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_tree(t_node **node)
{
	if ((*node) == NULL)
		return ;
	free_tree(&(*node)->left);
	free_tree(&(*node)->right);
	free(*node);
	*node = NULL;
}