/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:45:39 by akharraz          #+#    #+#             */
/*   Updated: 2022/10/15 23:02:33 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include <unistd.h>
#include <stdio.h>

int ft_cd(char *path)
{
	return 0;
}

int main(void)
{
	int i;
	
	i = chdir("..");
	printf("%d\n", i);
	return 0;
}