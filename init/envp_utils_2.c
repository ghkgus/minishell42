/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:33:15 by hwasong           #+#    #+#             */
/*   Updated: 2025/03/20 20:33:16 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	update_envp(t_envp_list *envp_list, char *key, char *value)
{
	t_envp	*current;
	t_envp	*new_node;

	current = envp_list -> head;
	while (current)
	{
		if (ft_strcmp(current -> key, key) == 0)
		{
			free(current -> value);
			current -> value = ft_strdup(value);
			current -> modified = 1;
			return ;
		}
		current = current -> next;
	}
	new_node = (t_envp *)malloc(sizeof(t_envp));
	new_node -> key = ft_strdup(key);
	new_node -> value = ft_strdup(value);
	new_node -> modified = 1;
	new_node -> next = NULL;
	add_node_last(envp_list, new_node);
}
