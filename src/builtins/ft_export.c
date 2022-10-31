/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:30:16 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/31 06:58:48 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env_node	*search_env_node(t_env *env, char *key)
{
	t_env_node *node;

	node = env->head;
	while (node)
	{
		if (!ft_strcmp(key, node->key))
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	ft_export(char **cmd, t_env *env)
{
	int			i;
	int			mode;
	char		*key;
	char		*value;
	t_sub		sub;
	t_env_node	*node;
	
	i = 1;
	ft_bzero((void *)&sub, sizeof(t_sub));
	if (!cmd[i])
	{
		export_print(env);
		return ;
	}
	while (cmd[i])
	{
		mode = export_isvalid(cmd[i], &sub);
		key = ft_substr(cmd[i], sub.start, sub.end);
		if (mode == 3 || mode == 1)
		{
			value = ft_substr(cmd[i], sub.end + 1, ft_strlen(cmd[i]) - sub.end);
			add_or_change_value(env, key, value);
		}
		if (mode == 2)
		{
			value = ft_substr(cmd[i], sub.end + 2, ft_strlen(cmd[i]) - sub.end);
			add_or_change_value(env, key, export_strjoin(get_value(env, key), value));
			free(value);
		}
		i++;
	}
}
