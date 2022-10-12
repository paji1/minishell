// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   cmd.c                                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/09/25 00:05:03 by tel-mouh          #+#    #+#             */
// /*   Updated: 2022/10/05 17:24:16 by tel-mouh         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minishell.h"

// /**
//  * @brief  get the PATH variable 
//  * 
//  * @param env environment variables
//  * @return index of the PATH variable
//  */ 
// static int	get_path(char **env)
// {
// 	int	i;

// 	i = -1;
// 	if (!env)
// 		return (-1);
// 	while(env[++i])
// 	{
// 		if (ft_strncmp(env[i], "PATH=", 5) == 0)
// 			return (i);
// 	}
// 	return (-1);
// }

// /**
//  * @brief  check if the command has an executing file
//  * 
//  * @param node tree node
//  * @param env environment variables
//  * @return the path to the command example : "\bin\ls"
//  */ 
// int	check_cmd(t_node *node, char **env, char **path)
// {
// 	int		i; // just an index
// 	int		j; // just an index
// 	t_sub	sub;
// 	char	*subtr;
// 	char	*jointr;
// 	int		found;

// 	sub.start = 5;
// 	i = get_path(env);
// 	if (i == -1)
// 		return -1;
// 	j = 0;
// 	while (env[i][j])
// 	{
// 		if(env[i][j] == ':')
// 		{
// 			// found = 3;
// 			sub.end = j;
// 			subtr = ft_substr(env[i], sub.start, sub.end - sub.start + 1);
// 			if (!subtr)
// 				return -1;
// 			subtr[sub.end - sub.start] = '/';
// 			sub.start = sub.end + 1;
// 			jointr = ft_strjoin(subtr, node->token.token);
// 			if (!jointr)
// 				return free(subtr), -1;
// 			if(access(jointr, X_OK) != -1)
// 				return(free(subtr), *path = jointr ,1);
// 			// if(access(jointr, F_OK) != -1)
// 			// 	found == 0;
// 			free(subtr);
// 			free(jointr);
// 		}
// 		j++;
// 	}
// 	return found;
// }

char **qto_tab(t_node *node)
{
	char	**tab;
	int		size;
	int		i;

	i = 0;
	if (!node)
		return NULL;
	if (node->token.args_q)
		size = node->token.args_q->size + 2;
	else
		size = 2;
	tab = malloc(sizeof(tab) * size);
	if (!tab)
		return NULL;
	tab[0] = node->token.token;
	if (!node->token.args_q)
		return tab[1] = NULL, tab;
	while (++i < size - 1)
	{
		tab[i] = q_n_get(node->token.args_q)->data->token.token;
	}
	return tab[size - 1] = NULL, tab;
}
