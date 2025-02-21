/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:53:24 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/21 14:53:26 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_shell(t_shell *shell, char **envp)
{
	shell -> envp = copy_envp(envp);
	shell -> process_list = NULL;
}

char    **copy_envp(char **envp)
{
	int		i;
	int		count;
	char	**new_envp;

	i = 0;
	count = 0;
	while (envp[count])
		count++;
	new_envp = malloc(sizeof(char *) * (count +1));
	if (!new_envp)
		return NULL;
	while (envp[i])
	{
		new_envp[i] = strdup(envp[i]);
		i++;
	}
	new_envp[i] = NULL;

	return new_envp;
}
