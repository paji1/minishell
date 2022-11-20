/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:45:36 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/20 10:01:19 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mode_init(t_export *export, t_env *env, char **cmd)
{
	export->mode = export_isvalid("export", cmd[export->i], &export->sub);
	export->key = ft_substr(cmd[export->i], export->sub.start, export->sub.end);
	export->node = search_env_node(env, export->key);
	if (export->node)
	{
		free (export->key);
		export->key = ft_strdup(export->node->key);
	}
}

static int	export_is_append(char *cmd, int i)
{
	return (cmd[i] == '+' && cmd[i + 1] == '=');
}

char	*export_strjoin(char *s1, char *s2)
{
	int		i[2];
	int		len[2];
	char	*new;

	if (!s1)
		s1 = ft_strdup("");
	i[0] = 0;
	i[1] = 0;
	len[0] = ft_strlen(s1) + ft_strlen(s2);
	len[1] = ft_strlen(s1);
	new = malloc(len[0] + 1);
	if (new == 0)
		return (NULL);
	while (i[0] < len[0])
	{
		while (i[0] < len[1])
		{
			new[i[0]] = s1[i[0]];
			i[0]++;
		}
		new[i[0]] = s2[i[1]];
		i[0]++;
		i[1]++;
	}
	return (new[i[0]] = '\0', free(s1), new);
}

int	export_isvalid(char *name, char *cmd, t_sub *sub)
{
	int	i;

	i = 1;
	sub->end = 1;
	if (!(ft_isalpha(cmd[0]) || cmd[0] == '_'))
		return (printf("minishell: %s: `%s': not a valid identifier\n"\
		, name, cmd), -1);
	while (cmd[i])
	{
		if (export_is_append(cmd, i))
			return (2);
		if (!ft_isalnum(cmd[i]) && cmd[i] != '=' && cmd[i] != '_')
			return (printf("minishell: %s: `%s': not a valid identifier\n"\
			, name, cmd), -1);
		if (cmd[i] == '=')
			return (1);
		sub->end++;
		i++;
	}
	return (3);
}

t_env_node	*search_env_node(t_env *env, char *key)
{
	t_env_node	*node;

	node = env->head;
	while (node)
	{
		if (!ft_strcmp(key, node->key))
			return (node);
		node = node->next;
	}
	return (NULL);
}
