/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:20:25 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/13 21:48:14 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void expand_key(char **str, size_t start, size_t end, t_env *env)
{
	char *first;
	char *second;
	char *value;
	char *temp;

	if (end == start)
		return ;
	first = ft_substr(*str, 0, start);
	second = ft_strdup(*str + end);
	value = allocate_to_value(str, start, end - start ,env);
	temp = ft_strjoin(first, value);
	if (!value[0])
		free(value);
	free(first);
	first = ft_strjoin(temp, second);
	free(temp);
	free(second);
	free(*str);
	*str = first;
}


void	expand_str(char **str, t_env *env)
{
	char	*temp;
	t_quote quote;
	int		i;

	i = -1;
	temp = *str;
	ft_bzero(&quote, sizeof(t_quote));
	while (temp[++i])
	{
		quote_handle(&quote, i, temp);
		if (temp[i] == '$' && quote.quote != '\'' )
		{
			expand_key(str, i, count_lent(&temp[i]) + i + 1, env);
			i--;
			temp = *str;
		}
	}
	expand_string_toquote(str, env);
}


// void	expander(char **str, t_env *env)
// {
	
	
// }