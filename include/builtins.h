/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:29:53 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/23 06:34:52 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		ft_isbuiltin(char *str);
void	ft_echo(char **cmd);
int		ft_pwd(t_env *env);
void    ft_env(t_env *env);
void    ft_cd(char  **cmd);
#endif /* !BUILTINS_H */