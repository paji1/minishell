/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:28:35 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/18 19:34:31 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* enum SPEACIAL {
 	OR,AND,PIP,REDIRECT_SO,REDIRECT_Si,APPEND,HEREDOC
 };
 */
int	is_special(char *str)
{
	char	*twochar;

	twochar = ft_substr(str, 0, 2);
	if (!twochar)
		return (-1);
	if (!ft_strcmp("||", twochar) || !ft_strcmp("&&", twochar))
		return (free(twochar), 2);
	else if (!ft_strcmp(">>", twochar) || !ft_strcmp("<<", twochar))
		return (free(twochar), 2);
	if (ft_strchr("|<>()", twochar[0]))
		return (free(twochar), 1);
	return (free(twochar), 0);
}
