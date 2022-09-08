/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 02:09:50 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/08 17:52:42 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief initialize vars structure
 * 
 * @param vars struct inside main function
 */
void	init(t_vars *vars)
{
	vars->buff = NULL;
	vars->base_name = NULL;
	vars->root = NULL;
}


/**
 * @brief create a new token and get value from t_token
 * 
 * @return t_node* new allocated node to put in tree
 */
t_node *new_tnode(void)
{
	t_node *new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return NULL;
	new->left = NULL;
	new->right = NULL;
	return new;
}