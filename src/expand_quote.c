/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:45:02 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/14 19:44:38 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void expand_quote(char **str, size_t start, size_t end)
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
	if (second)
		free(second);
	if (value)
	free(value);
	free(*str);
	*str = first;
}

static int count_sub(int	i, int quote, t_sub *sub)
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

void expand_string_toquote(char **str, t_env *env)
{
	t_sub	sub;
	t_quote quote;
	char	*temp;
	int	i;

	i = -1;
	temp = *str;
	ft_bzero(&sub, sizeof(t_sub));
	ft_bzero(&quote, sizeof(t_quote));
	while (temp[++i])
	{
		if (count_sub(i, quote_handle(&quote, i, temp), &sub))
		{
			expand_quote(str, sub.start, sub.end);
			temp = *str;
			ft_bzero(&sub, sizeof(t_sub));
			i -= 2;
		}
	}
}
