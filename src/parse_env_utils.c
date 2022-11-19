/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 04:09:04 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/19 02:03:22 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	split_with_equal(t_env_node *node, char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '=')
		;
	node->key = ft_substr(str, 0, i);
	if (!node->key)
		return (1);
	node->value = ft_strdup(&str[i + 1]);
	if (!node->value)
		return (1);
	return (0);
}

int	size_env(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
		i++;
	return (i);
}

void	print_env_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		ft_putendl_fd(tab[i], 2);
}

int	ignore_oldpwd(t_env_node *node)
{	
	if (ft_strcmp("OLDPWD", node->key))
		return (0);
	free(node->key);
	free(node->value);
	free(node);
	return (1);
}
