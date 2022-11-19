/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:03:23 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/18 22:22:51 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_lent(char *key)
{
	size_t	i;

	i = 1;
	while ((ft_isalnum(key[i]) || (key[i] == '?' && key[i - 1] == '$')) \
		&& key[i] && key[i] != '$' && key[i] != '\"' && key[i] != '\'')
		i++;
	if (i >= 1 && key[i] == '$' && key[i - 1] == '$')
		i++;
	return (i - 1);
}

char	*allocate_to_value(char **str, size_t start, size_t end, t_env *env)
{
	char	*key;
	char	*value;

	key = ft_substr(*str, start + 1, end - 1);
	if (!ft_strcmp(key, "?"))
		return (free(key), ft_itoa(g_exit_status));
	if (!key)
		return (NULL);
	value = get_value(env, key);
	free(key);
	if (!value)
		return (ft_strdup(""));
	return (value);
}

int	is_delim(char *str, int i)
{
	if (i < 3)
		return (0);
	while (is_space(str[--i]))
		;
	if (str[i - 1] == '<' && str[i] == '<')
		return (1);
	return (0);
}
