/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:43:29 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/21 15:43:59 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include <readline/readline.h>

void	minishell_loop(t_shell *shell, char **envp);
char	*prompt_read(void);
void	clear_process(t_process *process_list, char *input);
#endif
