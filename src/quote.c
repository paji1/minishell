/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:51:36 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/21 05:45:27 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief hande quote to continue loop in parse function
 * 
 * @param quote struct to handel quote
 * @param i counter inside parse function
 * @param buff return line of readline
 * @return int if inside quote or not
 */

int	quote_handle(t_quote *quote, int i, char *buff)
{
	if (!ft_strchr("\"'", buff[i]) && quote->in_quote == FALSE)
		return (0);
	if (!ft_strchr("\"'", buff[i]) && quote->in_quote == TRUE)
		return (1);
	if (quote->quote == buff[i] && quote->in_quote == TRUE)
		return (quote->in_quote = FALSE, quote->quote = '\0', 2);
	if (ft_strchr("\"'", buff[i]) && quote->in_quote == FALSE)
		return (quote->in_quote = TRUE, quote->quote = buff[i], 1);
	return (0);
}
