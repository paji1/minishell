/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:29:53 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/24 04:51:02 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		ft_isbuiltin(char *str);
void	ft_echo(char **cmd);
int		ft_pwd(t_env *env);
void	ft_env(t_env *env);
int		ft_cd(char  **cmd, t_env *env);
#endif /* !BUILTINS_H */