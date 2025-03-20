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
	shell -> envp = init_envp(envp);
	shell -> process_list = NULL;
}

t_envp_list	*init_envp(char **envp)
{
	int			i;
	t_envp_list	*copy_envp_list;
	t_envp		*envp_node;

	i = 0;
	copy_envp_list = (t_envp_list *)malloc(sizeof(t_envp_list));
	if (!copy_envp_list)
		return (0);
	copy_envp_list -> head = NULL;
	copy_envp_list -> tail = NULL;
	while (envp[i])
	{
		envp_node = create_envp_node(envp[i]);
		if (!envp_node)
		{
			clear_envp_list(copy_envp_list);
			return NULL;
		}
		add_node_last(copy_envp_list, envp_node);
		i++;
	}
	return (copy_envp_list);
}
