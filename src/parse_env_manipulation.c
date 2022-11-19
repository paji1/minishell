/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_manipulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:10:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/18 23:06:36 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_node	*new_env_node(void)
{
	t_env_node	*node;

	node = malloc(sizeof(t_env_node));
	if (!node)
		return (NULL);
	node->is_env = 1;
	node->key = NULL;
	node->value = NULL;
	node->next = NULL;
	return (node);
}

static int	remove_first(t_env *env, char *key)
{
	t_env_node	*tmp;

	if (ft_strcmp(env->head->key, key))
		return (0);
	tmp = env->head;
	if (env->head->next)
		env->head = env->head->next;
	else
	{
		env->head = NULL;
		env->tail = NULL;
	}
	free(tmp->key);
	free(tmp->value);
	free(tmp);
	return (1);
}

static void	remove_rest(t_env *env, char *key)
{
	t_env_node	*tmp;
	t_env_node	*tmp_next;

	tmp = env->head;
	while (tmp)
	{
		if (tmp->next && !ft_strcmp(tmp->next->key, key))
		{
			tmp_next = tmp->next;
			if (tmp->next->next)
				tmp->next = tmp->next->next;
			else
			{
				env->tail = tmp;
				tmp->next = NULL;
			}
			free(tmp_next->key);
			free(tmp_next->value);
			free(tmp_next);
		}
		tmp = tmp->next;
	}
}

void	remove_env_node(t_env *env, char *key)
{
	if (!env || !env->head || !key)
		return ;
	env->size -= 1;
	env->is_change = 1;
	if (remove_first(env, key))
		return ;
	remove_rest(env, key);
}

int	free_and_allocate(t_env *env)
{
	if (env->is_change == 0)
		return (1);
	free_tab(env->env_tab);
	env->env_tab = env_lst_to_tab(env);
	if (!env->env_tab)
		return (-1);
	env->is_change = 0;
	return (0);
}
