/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:30:16 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/14 03:33:59 by tel-mouh         ###   ########.fr       */
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


int	ft_export(char **cmd, t_env *env)
{
	int			i;
	int			mode;
	int			err;
	char		*key;
	char		*value;
	t_sub		sub;
	t_env_node	*node;
	
	i = 0;
	err = 0;
	node = NULL;
	ft_bzero((void *)&sub, sizeof(t_sub));
	if (!cmd[i])
		return export_print(env), 0;
	while (cmd[++i])
	{
		mode = export_isvalid("export", cmd[i], &sub);
		key = ft_substr(cmd[i], sub.start, sub.end);
		node = search_env_node(env, key);
			
		if (node)
		{
			free (key);
			key = node->key;
		}
		if (mode == -1)
		{
			free(key);
			err = 1;
			continue ;
		}
		if (mode == 1)
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
		if (mode == 3 && !node)
		{
			value = ft_substr(cmd[i], sub.end + 1, ft_strlen(cmd[i]) - sub.end);
			add_or_change_value(env, key, value);
			node = search_env_node(env, key);
			node->is_env = 0;
		}
	}
	return (err);
}
