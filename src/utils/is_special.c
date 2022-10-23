/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:28:35 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/16 01:34:59 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// enum SPEACIAL {
// 	OR,AND,PIP,REDIRECT_SO,REDIRECT_Si,APPEND,HEREDOC
// };
int is_special(char *str)
{
	char *twochar; 
	
	twochar = ft_substr(str, 0, 2);
	if (!twochar)
		return -1;
	if (!ft_strcmp("||", twochar) || !ft_strcmp("&&", twochar))
		return free(twochar), 2;
	else if (!ft_strcmp(">>", twochar) || !ft_strcmp("<<", twochar))
		return free(twochar), 2;
	if (ft_strchr("|<>()", twochar[0]))
		return (free(twochar), 1);
	return (free(twochar), 0);
}