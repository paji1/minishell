/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_manipulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:10:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/13 22:17:44 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_env_node	*new_env_node(void)
{
	t_env_node *node = malloc(sizeof(t_env_node));
	if (!node)
		return NULL;
	node->is_env = 1;
	node->key = NULL;
	node->value = NULL;
	node->next = NULL;
	return node;
}

void	add_to_env_tail(t_env *env, t_env_node *new)
{
	if (!new)
		return ;
	if (!env->tail)
	{
		env->head =	 new;
		env->tail = new;
	}
	else
	{
		env->tail->next = new;
		env->tail = new;
	}
	env->size += 1;
}

static int	remove_first(t_env *env, char *key)
{
	t_env_node *tmp;

	if (ft_strcmp(env->head->key, key))
		return 0;
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
	return 1;
}

static void	remove_rest(t_env *env, char *key)
{
	t_env_node *tmp;
	t_env_node *tmp_next;

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

static int	is_in_env_change(t_env_node *head, char *key, char *value)
{
	while (head)
	{
		if (!ft_strcmp(head->key, key))
		{
			free(head->value);
			head->value = value;
			return 1;
		}
		head = head->next;
	}
	return 0;
}

int free_and_allocate(t_env *env)
{
	if (env->is_change == 0)
		return 1;
	free_tab(env->env_tab);
	env->env_tab = env_lst_to_tab(env);
	if (!env->env_tab)
		return -1;
	env->is_change = 0;
	return 0;
}

int	add_or_change_value(t_env *env, char *key, char *value)
{
	t_env_node *new;

	if (!key && !value)
		return -1;
	if (!value)
		return free(key), 1;
	if (!key)
		return free(value), 1;
	if (!is_in_env_change(env->head, key, value))
	{
		new = new_env_node();
		new->key = key;
		new->value = value;
		add_to_env_tail(env , new);
	}
	env->is_change = 1;
	return 0;
}


char	*get_value(t_env *env, char *key)
{
	t_env_node *tmp;

	tmp = env->head;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
			return tmp->value;
		tmp = tmp->next;
	}
	return NULL;
}