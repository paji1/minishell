/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_check_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:29:09 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/19 03:37:21 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*search_path(t_env *env)
{
	t_env_node	*node;

	node = env->head;
	while (node)
	{
		if (ft_strncmp(node->key, "PATH", 4) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

static int	fill_sub(char *subtr, t_sub *sub)
{
	subtr[sub->end - sub->start] = '/';
	sub->start = sub->end + 1;
	return (0);
}

static int	search_cmd(char *cmd, char *env, char **path)
{
	t_sub	sub;
	char	*subtr;
	char	*jointr;

	ft_bzero(&sub, sizeof(t_sub));
	subtr = NULL;
	while (env[sub.end])
	{
		if (env[sub.end] == ':')
		{
			subtr = ft_substr(env, sub.start, sub.end - sub.start + 1);
			if (!subtr)
				return (ft_putstr_fd("allocation failed\n", 2), -1);
			fill_sub(subtr, &sub);
			jointr = ft_strjoin(subtr, cmd);
			if (!jointr)
				return (free(subtr), ft_putstr_fd("allocation failed\n", 2), -1);
			if (access(jointr, F_OK) != -1)
				return (free(subtr), *path = jointr, 1);
			free(jointr);
			free(subtr);
		}
		sub.end++;
	}
	return (-1);
}

int	check_cmd(t_node *node, t_env *env, char **path)
{
	char	*key;

	if (check_if_path(node->token.token))
	{
		(*path) = node->token.token;
		if (check_permission(*path) < 0)
			return (-1);
		return (check_if_dir(*path));
	}
	key = search_path(env);
	if (!key)
		return (print_cnf(node->token.token), -4);
	if (search_cmd(node->token.token, key, path) == -1)
		return (print_cnf(node->token.token), -4);
	return (check_permission(*path));
}
