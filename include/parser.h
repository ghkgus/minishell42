/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikim2 <yikim2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:27:12 by yikim2            #+#    #+#             */
/*   Updated: 2025/03/12 00:27:12 by yikim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <signal.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>

typedef enum {
    M_WORD,
    M_ENV,
    M_PIPE,
    REDIR_IN,
    REDIR_OUT,
    REDIR_APPEND,
    HEREDOC
} t_token_type;

typedef struct c_token{
    int     type;
    char    *str;
} c_token;

struct m_list;

typedef struct m_list{
    c_token			content;
    struct m_list	*next;
} m_list;


void	sigint_handler(int sig);
void	set_signal();
void	heredoc_sigint_handler(int sig);
void	heredoc_set_signal();

int		_sep(char c, char sep);
int		word(char *str, char sep);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
static char	**youcandoit(char *s, char c, char **icha);
char	**ft_split(char const *s, char c);

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *src);
int		ft_strcmp(const char *s1, const char *s2);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_realloc(void *ptr, size_t newsize);
int     ft_isalnum(int c);

int		is_char(char c, char d);
int		is_quote(char c, char d);
int		is_special_char(char c, char d);
int		is_space(char c);

void	parse_to_token(char* line, m_list **t_list);
int		handle_backslash(char *line, int *i);
void	add_token(m_list **head, int type, char *str);

void	parse_to_process(m_list *t_list, t_process_list *process_list, t_shell *shell);
void	process_to_process_list(t_process_list *head, t_process *new_process);
int		open_file_for_redirection(char *filename, int type);
int     here_doc(char *delimiter);

char    *get_envp(char *str);
char    *find_envp_key(char *str);
char    *heredoc_get_envp(char *str);

void    get_parsing_info(t_shell *shell ,char *input);

#endif


// #ifndef PARSER_H
// # define PARSER_H

// #include "../include/struct.h"

// t_process_list *get_parsing_info(t_shell *shell, char *input);

// #endif
