/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:13:27 by hwasong           #+#    #+#             */
/*   Updated: 2025/02/20 20:14:21 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "struct.h"

# include <stdio.h>
# include <readline/readline.h>

void	init_env(t_shell *shell, char **envp);

#endif