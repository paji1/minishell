/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:04:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/07/08 20:06:17 by tel-mouh         ###   ########.fr       */
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

// void insert(t_node **node, t_node *new)
// {	
// 	;
// }