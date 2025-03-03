/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikim2 <yikim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:25:39 by yikim2            #+#    #+#             */
/*   Updated: 2025/02/24 13:56:55 by yikim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void parse_to_process(m_list *t_list, t_process_list *process_list)
{

    m_list *current_list = t_list;
    t_process *current_process = NULL;
    int args_count = 0;
    int fd_in = STDIN_FILENO;
    int fd_out = STDOUT_FILENO;

    while(current_list)
    {
        if(current_list->content.type == M_WORD)
        {
            int pipe_fd[2];

            if (pipe(pipe_fd) == -1) {
                perror("pipe error");
                exit(EXIT_FAILURE);
            }
            if (ft_strcmp(current_list->content.str, "|") == 0) {
                if (current_process != NULL) {
                    current_process->out = pipe_fd[1];
                    process_to_process_list(process_list, current_process);
                    process_list->count++;
                    current_process = NULL;
                }
                fd_in = pipe_fd[0];
                args_count = 0;
            }
            else{
                if(current_process == NULL){
                    current_process = (t_process *)malloc(sizeof(t_process));
                    current_process->cmd_name = ft_strdup(current_list->content.str);
                    current_process->av = (char **)malloc(sizeof(char *) * (args_count + 1));
                    current_process->av[args_count++] = ft_strdup(current_list->content.str);
                    current_process->av[args_count] = NULL;
                    current_process->in = fd_in;
                    current_process->out = fd_out;
                    current_process->is_redirected = 0;
                    current_process->envp = NULL;
                    current_process->next = NULL;
                }
                else{
                    current_process->av = realloc(current_process->av, sizeof(char *) * (args_count + 2));
                    current_process->av[args_count++] = ft_strdup(current_list->content.str);
                    current_process->av[args_count] = NULL;
                }
            }
        }
        else if (current_list->content.type == REDIR_IN || current_list->content.type == REDIR_OUT || current_list->content.type == REDIR_APPEND || current_list->content.type == HEREDOC) {
            if (current_list->next && current_list->next->content.type == M_WORD) {
                int fd = open_file_for_redirection(current_list->next->content.str, current_list->content.type);
                
                if (fd == -1) {
                    perror("Error opening file");
                    exit(1);
                }
                
                if (current_list->content.type == REDIR_IN) {
                    fd_in = fd;
                    current_process->in = fd_in;
                } else if (current_list->content.type == REDIR_OUT || current_list->content.type == REDIR_APPEND){
                    fd_out = fd;
                    current_process->out = fd_out;
                } else if (current_list->content.type == HEREDOC) {
                    fd_in = fd;
                    current_process->in = fd_in;
                }
                printf("fd in value: %d \n", fd_in);
                printf("fd out value: %d \n", fd_out);

                current_list = current_list->next;
                
                if (current_process != NULL) {
                    current_process->is_redirected = 1;
                }
                printf("is redirected : %d \n", current_process->is_redirected);
            }
        }
        current_list = current_list->next;
    }
    if (current_process != NULL) {
        process_to_process_list((process_list), current_process);
        process_list->count++;
    }
    current_process = NULL;
}

void process_to_process_list(t_process_list *head, t_process *new_process)
{
    t_process *new;
    
    if ((head)->head == NULL) {
        (head)->head = (head)->tail = new_process;
    } else {
        new = (head)->head;
        while(new->next)
            new = new->next;
        new->next = new_process;
        (head)->tail = new_process;
    }
}

int	here_doc(char *delimiter)
{
	int		pipefd[2];
	char	*line;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	line = readline("heredoc> ");
	while (line)
	{
		line = heredoc_get_envp(line);
		if (ft_strncmp(line, delimiter, ft_strlen(line) - 1) == 0)
			break ;
		write(pipefd[1], line, strlen(line));
		write(pipefd[1], "\n", 1);
		free(line);
		line = readline("heredoc> ");
	}
	free(line);
	close(pipefd[1]);
	return (pipefd[0]);
}

int open_file_for_redirection(char *filename, int type)
{
    int fd;
    fd = -1;
    
    if (type == REDIR_IN) {
        fd = open(filename, O_RDONLY);
    } else if (type == REDIR_OUT) {
        fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    } else if (type == REDIR_APPEND) {
        fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    } else if (type == HEREDOC) {
        fd = here_doc(filename);
    }
    return fd;
}
