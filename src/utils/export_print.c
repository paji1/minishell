/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:33:49 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/29 05:04:21 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	indexing_export(t_env *env)
{
	int			i;
	t_env_node	*head;
	t_env_node	*tmp;

	head = env->head;
	tmp = env->head;
	while (head)
	{
		i = 0;
		while (tmp)
		{
			if (ft_strcmp(head->key, tmp->key) > 0)
				i++;
			tmp = tmp->next;
		}
		head->index = i;
		head = head->next;
		tmp = env->head;
	}
}

static void	print_export(t_env *env)
{
	t_env_node	*node;
	int			i;

	i = 0;
	node = env->head;
	while (node)
	{
		if (node->index == i)
		{
			printf("declare -x %s=\"%s\"\n", node->key, node->value);
			i++;
			node = env->head;
		}
		else
			node = node->next;
	}
}

void	export_print(t_env *env)
{
	indexing_export(env);
	print_export(env);
}
