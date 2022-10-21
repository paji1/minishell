/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:20:25 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/21 06:48:48 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	count_lent(char *key)
{
	size_t	i;

	i = 1;
	while (key[i] != ' ' && key[i] && key[i] != '$' && key[i] != '\"' && key[i] != '\'')
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

void expand_quote(char **str, size_t start, size_t end)
{
	char *first;
	char *second;
	char *value;
	char *temp;

	if (end == start)
		return ;
	first = ft_substr(*str, 0, start);
	temp = ft_substr(*str, start + 1, end -start-1);
	value = ft_strjoin(first, temp);
	free(first);
	free(temp);
	second = ft_strdup(*str + end + 1);
	first = ft_strjoin(value, second);
	free(second);
	free(value);
	free(*str);
	*str = first;
}

int count_sub(int	i, int quote, t_sub *sub)
{
	static int flag;

	if (flag == 0 && quote == 1)
	{
		flag = 1;
		sub->start = i;
	}
	if (flag == 1 && quote == 2)
	{
		flag = 0;
		sub->end = i;
		return 1;
	}
	return 0;
}

void	expand_str(char **str, t_env *env)
{
	char	*temp;
	t_sub	sub;
	t_quote quote;
	int		i;
	

	i = -1;
	temp = *str;
	ft_bzero(&quote, sizeof(t_quote));
	ft_bzero(&sub, sizeof(t_sub));
	while (temp[++i])
	{
		quote_handle(&quote, i, temp);
		if (temp[i] == '$' && quote.quote != '\'')
		{
			expand_key(str, i, count_lent(&temp[i]) + i + 1, env);
			temp = *str;
		}
	}
	i = -1;
	ft_bzero(&quote, sizeof(t_quote));
	while (temp[++i])
	{
		if (count_sub(i, quote_handle(&quote, i, temp), &sub))
		{
			expand_quote(str, sub.start, sub.end);
			temp = *str;
			ft_bzero(&sub, sizeof(t_sub));
		}
	}
}


// void	expander(char **str, t_env *env)
// {
	
	
// }