/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:57:42 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/21 17:57:44 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

void	execute_commands(t_shell *shell, t_process_list *process_list);
void	execute_single_process(t_process *process, t_shell *shell);
void	execute_multi_process(t_process_list *process_list, \
t_shell *shell, pid_t *pids);
#endif
