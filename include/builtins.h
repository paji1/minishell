/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:29:53 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/01 18:59:05 by akharraz         ###   ########.fr       */
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
// ###               export_funcs                    ###
// #####################################################
void	export_print(t_env *env);
char	*export_strjoin(char *s1, char *s2);
int		export_isvalid(char *cmd, t_sub *sub);
#endif /* !BUILTINS_H */