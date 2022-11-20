/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:30:16 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/20 10:01:10 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	mode_one(t_export *export, t_env *env, char **cmd)
{
	export->value = ft_substr(cmd[export->i], export->sub.end + 1, \
	ft_strlen(cmd[export->i]) - export->sub.end);
	add_or_change_value(env, export->key, export->value);
	if (export->node)
		export->node->is_env = 1;
}

static void	mode_two(t_export *export, t_env *env, char **cmd)
{
	export->value = ft_substr(cmd[export->i], export->sub.end + 2, \
	ft_strlen(cmd[export->i]) - export->sub.end);
	add_or_change_value(env, export->key, \
	export_strjoin(get_value(env, export->key), export->value));
	if (export->node)
		export->node->is_env = 1;
	free(export->value);
}

static void	mode_three(t_export *export, t_env *env, char **cmd)
{
	export->value = ft_substr(cmd[export->i], export->sub.end + 1, \
	ft_strlen(cmd[export->i]) - export->sub.end);
	add_or_change_value(env, export->key, export->value);
	export->node = search_env_node(env, export->key);
	export->node->is_env = 0;
}

static int	exec_mode(t_export *export, t_env *env, char **cmd)
{
	if (export->mode == 1)
		mode_one(export, env, cmd);
	if (export->mode == 2)
		mode_two(export, env, cmd);
	if (export->mode == 3)
	{
		if (export->node)
		{
			free(export->key);
			return (1);
		}
		mode_three(export, env, cmd);
	}
	return (0);
}

int	ft_export(char **cmd, t_env *env)
{
	t_export	export;

	ft_bzero((void *)&export, sizeof(t_export));
	if (!cmd[1])
		return (export_print(env), 0);
	while (cmd[++export.i])
	{
		mode_init(&export, env, cmd);
		if (export.mode == -1)
		{
			free(export.key);
			export.err = 1;
			continue ;
		}
		if (exec_mode(&export, env, cmd))
			continue ;
	}
	return (export.err);
}
