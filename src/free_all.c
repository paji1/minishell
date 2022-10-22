/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:13:18 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/22 02:46:35 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void free_node_env(t_env_node *node)
{
	if (!node)
		return ;
	free_node_env(node->next);
	free(node->key);
	free(node->value);
	free(node);
}


void free_env(t_env *env)
{
    if (!env || !env->head)
        return ;
    free_tab(env->env_tab);
	free_node_env(env->head);
	free(env);
}

void free_pr(t_node *node)
{
	static t_node *pr;

	if (pr && pr->node_type == PR)
	{
		free(pr->token.token);
		free(pr);
	}
	pr = node;
}

void free_tree(t_node *root)
{
    if (!root)
        return ;
    free_tree(root->left);
    free_tree(root->right);
    if (root->token.args_q)
        free_queue(root->token.args_q);
    if (root->token.redir)
        free_queue(root->token.redir);
    free(root->token.token);
    free(root);
}

void    free_all(t_vars *vars)
{
    if (vars->base_name)
        free(vars->base_name);
    if (vars->env)
        free_env(vars->env);
    if (vars->buff)
        free(vars->buff);
    free_stack(vars->roots);
    if (vars->root)
        free_tree(vars->root);
}