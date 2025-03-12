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

typedef struct s_process
{
    char    *cmd_name; // 프로그램 이름 (예 : ls, echo, cat ...)
    char    **av; // 뒤에 붙는 인자들 (예 : -l, -n, -a ... ; 여러개 붙을 수 있으니까)
    int     in; // 입력 파일 디스크립터 - (표준 입력, 리다이렉션 되면 파일디스크립터 값)
    int     out; // 출력 파일 디스크립터 - (표준 출력, 리다이렉션 되면 fd값)
    int     is_redirected; // 리다이렉션 유무 확인
    char    **envp; // 환경변수
    struct s_process *next; // 파이프 연결되어 있는 다음
} t_process;

typedef struct s_process_list
{
	int			count;
	t_process	*head;
	t_process	*tail;
}	t_process_list;

//isalnum, realloc 함수 구현 더블쿼트일때 환경변수 처리(export로 유동적이여서)

typedef struct s_shell
{ // 환경변수와 실행할 프로세스 리스트 저장하는 역할
	char	**envp; // 환경 변수 목록
	t_process_list	*process_list; // 현재 실행할 프로세스 리스트
}	t_shell;


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
