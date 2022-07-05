/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:04:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/04 16:18:27 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node *new_node(int data)
{
	t_node *new;
	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->level = 0;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void insert(t_node **node, t_node *new)
{	
	if ((*node) == NULL)
	{
		(*node) = new;
		return ;
	}
	(new->level)++;
	if (new->data < (*node)->data)
	{
		if ((*node)->left == NULL)
			(*node)->left = new;
		else
			insert(&(*node)->left, new);
	}
	else if (new->data > (*node)->data) 
	{
		if ((*node)->right == NULL)
			(*node)->right = new;
		else
			insert(&(*node)->right, new);
	}
}