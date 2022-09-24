/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exucute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:17:18 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/25 00:10:07 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"




void exucute(t_node *root,t_vars *vars)
{
	if (root == NULL)
		return ;


	exucute(root->left, vars);
	exucute(root->right, vars);
}