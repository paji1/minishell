/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:48:47 by akharraz          #+#    #+#             */
/*   Updated: 2022/09/28 17:48:48 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "types_pipe.h"

t_list	*ft_lstnew(char *cmd, int taha);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif
