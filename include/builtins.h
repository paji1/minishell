/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:29:53 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/18 21:37:25 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		ft_isbuiltin(char *str);
int		ft_cd(char **cmd, t_env *env);
int		ft_echo(char **cmd);
int		ft_pwd(t_env *env);
int		ft_env(t_env *env, char **cmd);
int		ft_unset(char **cmd, t_env *env);
int		ft_export(char **cmd, t_env *env);
int		ft_exit(char **cmd);

// #####################################################
// ###               export_funcs                    ###
// #####################################################
void	export_print(t_env *env);
char	*export_strjoin(char *s1, char *s2);
int		export_isvalid(char *name, char *cmd, t_sub *sub);
#endif /* !BUILTINS_H */