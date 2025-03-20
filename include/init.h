/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:39:53 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/21 16:39:54 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

void		init_shell(t_shell *shell, char **envp);
t_envp_list	*init_envp(char **envp);
t_envp		*create_envp_node(char *envp);
void		get_key_value(t_envp *node, char *envp, char *equal_sign);
void		add_node_last(t_envp_list *envp_list, t_envp *node);
void		clear_envp_list(t_envp_list *envp_list);
void		free_shell(t_shell *shell);
void		free_process(t_process_list *process_list, char *input);

#endif