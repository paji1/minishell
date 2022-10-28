/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:29:53 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/28 10:34:50 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		ft_isbuiltin(char *str);
int		ft_cd(char  **cmd, t_env *env);
void	ft_echo(char **cmd);
void    ft_pwd(t_env *env);
void	ft_env(t_env *env);
void	ft_unset(char **cmd ,t_env *env);
void	ft_export(char **cmd ,t_env *env);

// #####################################################
// ###                  export_funcs                ###
// #####################################################
void	export_print(t_env *env);

#endif /* !BUILTINS_H */