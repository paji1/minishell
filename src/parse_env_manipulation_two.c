/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_manipulation_two.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:40:54 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/18 20:43:24 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_in_env_change(t_env_node *head, char *key, char *value)
{
	while (head)
	{
		if (!ft_strcmp(head->key, key))
		{
			free(head->value);
			free(key);
			head->value = value;
			return (1);
		}
		head = head->next;
	}
	return (0);
}

void	add_to_env_tail(t_env *env, t_env_node *new)
{
	if (!new)
		return ;
	if (!env->tail)
	{
		env->head = new;
		env->tail = new;
	}
	else
	{
		env->tail->next = new;
		env->tail = new;
	}
	env->size += 1;
}

char	*get_value(t_env *env, char *key)
{
	t_env_node	*tmp;

	tmp = env->head;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}

int	add_or_change_value(t_env *env, char *key, char *value)
{
	t_env_node	*new;

	if (!key && !value)
		return (-1);
	if (!value)
		return (free(key), 1);
	if (!key)
		return (free(value), 1);
	if (!is_in_env_change(env->head, key, value))
	{
		new = new_env_node();
		new->key = key;
		new->value = value;
		add_to_env_tail(env, new);
	}
	env->is_change = 1;
	return (0);
}
