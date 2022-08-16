/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:11:33 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/08/16 05:49:37 by tel-mouh         ###   ########.fr       */
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

void	free_split(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	free_all(t_vars *vars)
{
	if (vars->node)
		free_tree(&vars->node);
	if (vars->tab_cmd)
		free_split(vars->tab_cmd);
	if (vars->cmd)
		free(vars->cmd);
	if (vars->base_name)
		free(vars->base_name);
}