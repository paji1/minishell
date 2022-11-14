/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:19:50 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/13 22:14:01 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**alloc_to_env(char **tab, t_env *env)
{
	char		**env_tab;
	int			i;
	t_env_node	*node;
	
	env_tab = malloc((size_env(tab) + 1) * sizeof(char *));
	i = -1;
	if (!env_tab)
		return NULL;
	while (tab[++i])
	{
		node = new_env_node();
		if (!node)
			return free_env(env), NULL;
		if (split_with_equal(node, tab[i]))
			return free_env(env), NULL;
		add_to_env_tail(env, node);
		env_tab[i] = ft_strdup(tab[i]);
		if (!env_tab[i])
			return free_env(env), free_tab(env_tab), NULL;
	}
	env_tab[i] = NULL;
	return env_tab;
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
		return NULL;
	tab = malloc((env->size + 1) * sizeof(char *));
	if (!tab)
		return NULL;
	while (tmp)
	{
		equal = ft_strjoin(tmp->key, "=");
		if (!equal)
			return free_tab(tab), NULL;
		tab[i] = ft_strjoin(equal, tmp->value);
		if (!tab[i])
			return free_tab(tab), free(equal), NULL;
		free(equal);
		i++;
		tmp = tmp->next;
	}
	return tab[i] = NULL, tab;
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
	vars->env->env_tab = alloc_to_env(env_tab, vars->env);
	if (!vars->env->env_tab)
		return (1);
	return (0);
}
