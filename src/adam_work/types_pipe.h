/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:47:02 by akharraz          #+#    #+#             */
/*   Updated: 2022/09/28 17:47:04 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_PIPE_H
# define TYPES_PIPE_H

typedef struct s_fds
{
	int fd[2];
	int	fd_out;
} t_fds;

typedef struct s_list{
	char			**cmd;
	int				taha;
	t_fds			*fds;
	struct s_list 	*next;
	struct s_list 	*previous;
} t_list;

#endif