/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:03:23 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/14 21:44:50 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_lent(char *key)
{
	size_t	i;

	i = 1;
	while (ft_isalnum(key[i]) && key[i] && key[i] != '$' && key[i] != '\"' && key[i] != '\'')
		i++;
	if (i >= 1 && key[i] == '$' && key[i - 1] == '$')
		i++;
	return i -1;
}

char *allocate_to_value(char **str, size_t start, size_t end, t_env *env)
{
	char	*key;
	char	*value;

	key = ft_substr(*str, start+1, end - 1);
	if (!key)
		return NULL;
	value = get_value(env, key);
	free(key);
	if (!value)
		return ft_strdup("");
	return value;
}