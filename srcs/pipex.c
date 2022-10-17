/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:47:00 by nel-masr          #+#    #+#             */
/*   Updated: 2021/11/22 17:00:06 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute(char *cmd, char **envp)
{
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
	int		i;
	char	*finalcmd;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = envp[i] + 5;
	cmd_paths = tweaked_split(path, ':');
	cmd_args = ft_split(cmd, ' ');
	i = 0;
	while (cmd_paths[i])
	{
		finalcmd = ft_strjoin(cmd_paths[i], cmd_args[0]);
		if (!(access(finalcmd, F_OK)))
			execve(finalcmd, cmd_args, envp);
		else
			i++;
		free(finalcmd);
	}
	t_free_that_string(cmd_args);
	t_free_that_string(cmd_paths);
	perror(cmd);
}

void	read_from_pipe(int outfile, char *cmd2, int pipefd[2], char **envp)
{
	if (dup2(outfile, 1) < 0)
		exit (1);
	if (dup2(pipefd[0], 0) < 0)
		exit (1);
	close(pipefd[1]);
	close(outfile);
	execute(cmd2, envp);
	exit (1);
}

void	write_in_pipe(int infile, char *cmd1, int pipefd[2], char **envp)
{
	if (dup2(infile, 0) < 0)
		exit (1);
	if (dup2(pipefd[1], 1) < 0)
		exit(1);
	close(pipefd[0]);
	close(infile);
	execute(cmd1, envp);
	exit (1);
}

void	pipex(int infile, int outfile, char **argv, char **envp)
{
	int	pipefd[2];
	int	childpid1;
	int	childpid2;
	int	status;

	if (pipe(pipefd) == -1)
	{
		perror("Pipe");
		exit (1);
	}
	childpid1 = fork();
	if (childpid1 == 0)
		write_in_pipe(infile, argv[2], pipefd, envp);
	childpid2 = fork();
	if (childpid2 == 0)
		read_from_pipe(outfile, argv[3], pipefd, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(childpid1, &status, 0);
	waitpid(childpid2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;

	if (argc == 5)
	{
		infile = open(argv[1], O_RDONLY/* | O_CREAT, 0644*/);
		outfile = open(argv[4], O_TRUNC | O_RDWR/* | O_CREAT,  0644*/);
		if (infile < 0 || outfile < 0)
			perror("open");
		pipex(infile, outfile, argv, envp);
	}
	else
		printf("USAGE\n\t./pipex infile cmd1 cmd2 outfile.\n");
}
