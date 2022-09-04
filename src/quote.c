/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:51:36 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/04 22:52:35 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int quote_handle(t_quote *quote, int i, char *buff)
{
    if (!ft_strchr("\"'", buff[i]) && quote->in_quote == FALSE)
        return  (0);
    if (!ft_strchr("\"'", buff[i]) && quote->in_quote == TRUE)
        return (1);
    if (quote->quote == buff[i] && quote->in_quote == TRUE)
        return quote->in_quote = FALSE , 1;
    if (ft_strchr("\"'", buff[i]) && quote->in_quote == FALSE)
        return quote->in_quote = TRUE, quote->quote =  buff[i] , 1;
    return 0;
}