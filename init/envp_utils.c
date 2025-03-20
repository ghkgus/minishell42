/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:53:36 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/21 14:53:37 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_envp	*create_envp_node(char *envp)
{
	t_envp	*node;
	char	*equal_sign;

	node = (t_envp *)malloc(sizeof(t_envp));
	if (!node)
		return NULL;
	equal_sign = ft_strchr(envp, "=");
	if (equal_sign)
	{
		node -> key = (char *)malloc(equal_sign - envp + 1);
		if (!node -> key)
		{
			free(node);
			return NULL;
		}
		get_key_value(node, envp, equal_sign);
	}
	else
	{
		node -> key = ft_strdup(envp);
		node -> value = NULL;
	}
	node -> next = NULL;
	node -> modified = 0;
	return (node);
}

void clear_envp_list(t_envp_list *envp_list)
{
	t_envp	*current;
	t_envp	*next;

	current = envp_list -> head;
	while (current)
	{
		next = current -> next;
		free(current -> key);
		free(current -> value);
		free(current);
		current = next;
	}
	free(envp_list);
}

void add_node_last(t_envp_list *envp_list, t_envp *node)
{
	if (!envp_list || !node)
		return ;
	if (envp_list -> head == NULL)
	{
		envp_list -> head = node;
		envp_list -> tail = node;
	}
	else
	{
		envp_list -> tail -> next = node; // 기존 tail의 next를 새로운 노드로 연결
		envp_list -> tail = node; // tail을 새로운 노드로 업데이트
	}
	node -> next = NULL;
}

void get_key_value(t_envp *node, char *envp, char *equal_sign)
{
	ft_memcpy(node -> key, envp, equal_sign - envp);
	node -> key[equal_sign - envp] = '\0';
	node -> value = ft_strdup(equal_sign + 1);
}
