/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:50:00 by nel-masr          #+#    #+#             */
/*   Updated: 2021/11/22 17:00:00 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PIPEX_H_
# define  _PIPEX_H_

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 4096

int		main(int argc, char **argv, char **envp);
void	pipex(int infile, int outfile, char **argv, char **envp);
void	write_in_pipe(int infile, char *cmd1, int pipefd[2], char **envp);
void	read_from_pipe(int outfile, char *cmd2, int pipefd[2], char **envp);
void	execute(char *cmd, char **envp);

char	*ft_strjoin(char *s1, char *s2);
char	**tweaked_split(char const *s,  char c);
char	**t_free_that_string(char **tab);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	**free_that_string(char **tab);

#endif
