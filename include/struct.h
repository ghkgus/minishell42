/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:26:26 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/20 20:26:50 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

typedef struct s_process
{
	char	*cmd_name;
	char	**av;
	int		in;
	int		out;
	int		is_redirected;
	char	**envp;
	struct s_process	*next;
}	t_process;

typedef struct s_process_list	
{
	int	count;
	t_process	*head;
	t_process	*tail;
}	t_process_list;


typedef struct s_shell
{
	char	**envp;
	t_process_list	*process_list;
}	t_shell;

#endif
