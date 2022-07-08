/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:04:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/07 04:53:44 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node *new_node(int data, int type)
{
	t_node *new;
	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->type = type;
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