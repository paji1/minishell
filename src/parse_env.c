/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:19:50 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/20 03:59:25 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**alloc_to_env(char **tab, t_env *env)
{
	char		**env_tab;
	int			i;
	int			sk;
	t_env_node	*node;

	env_tab = malloc((size_env(tab) + 1) * sizeof(char *));
	i = -1;
	sk = 0;
	if (!env_tab)
		return (NULL);
	while (tab[++i])
	{
		node = new_env_node();
		if (!node)
			return (free_env(env), NULL);
		if (split_with_equal(node, tab[i]))
			return (free_env(env), NULL);
		if (ignore_oldpwd(node, &sk))
			continue ;
		add_to_env_tail(env, node);
		env_tab[i - sk] = ft_strdup(tab[i]);
		if (!env_tab[i - sk])
			return (free_env(env), free_tab(env_tab), NULL);
	}
	return (env_tab[i - sk] = NULL, env_tab);
}

char	**env_lst_to_tab(t_env *env)
{
	char		**tab;
	char		*equal;
	t_env_node	*tmp;
	int			i;

	i = 0;
	tmp = env->head;
	if (!tmp)
		return (NULL);
	tab = malloc((env->size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (tmp)
	{
		equal = ft_strjoin(tmp->key, "=");
		if (!equal)
			return (free_tab(tab), NULL);
		tab[i] = ft_strjoin(equal, tmp->value);
		if (!tab[i])
			return (free_tab(tab), free(equal), NULL);
		free(equal);
		i++;
		tmp = tmp->next;
	}
	return (tab[i] = NULL, tab);
}

int	if_impty(t_vars *vars, char **env_tab)
{
	char		*path;
	const char	*new_tab[] = {
	[0] = "PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin",
	[1] = "PWD=",
	[2] = "SHLVL=1",
	[3] = "OLDPWD=1",
	[4] = NULL
	};

	if (*env_tab)
		return (1);
	path = malloc(PATH_MAX);
	if (!path)
		return (exit(12), -1);
	vars->env->env_tab = alloc_to_env((char **)new_tab, vars->env);
	getcwd(path, PATH_MAX);
	add_or_change_value(vars->env, ft_strdup("PWD"), ft_strdup(path));
	free(path);
	return (0);
}

void	increment_shell_level(t_env *env)
{
	char	*value;
	int		value_nb;

	value = get_value(env, "SHLVL");
	value_nb = ft_atoi(value);
	value_nb++;
	free(value);
	add_or_change_value(env, ft_strdup("SHLVL"), ft_itoa(value_nb));
}

int	init_env(t_vars *vars, char **env_tab)
{
	vars->env = malloc(sizeof(t_env));
	if (!vars->env)
		return (1);
	vars->env->head = NULL;
	vars->env->tail = NULL;
	vars->env->size = 0;
	vars->env->is_change = 0;
	if (if_impty(vars, env_tab))
		vars->env->env_tab = alloc_to_env(env_tab, vars->env);
	increment_shell_level(vars->env);
	if (!vars->env->env_tab)
		return (1);
	return (0);
}
