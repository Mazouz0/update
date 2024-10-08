
#include "minishell.h"

int	cp_arr(char **in_redir, char c)
{
	int	i;
	int cp;

	i = 0;
	cp = 0;
	while (in_redir[i])
	{
		if (in_redir[i][0] == c)
			cp++;
		i++;
	}
	return (i);
}

t_utils	*init_utils(char **redir)
{
	t_utils	*utils;

	utils = ft_malloc(sizeof(t_utils), 0);
	utils->fd = 0;
	utils->i = 0;
	utils->fds_in = ft_malloc(sizeof(int) * cp_arr(redir, '>'), 0);
	utils->fds_out = ft_malloc(sizeof(int) * cp_arr(redir, '<'), 0);
	utils->f_name = NULL;
	return (utils);
}

char	*get_r_name(char *redir, t_env *env)
{
	int		i;

	(void)env;
	i = 0;
	if (redir[i] == '<' || redir[i] == '>')
		i++;
	if (redir[i] == '<' || redir[i] == '>')
		i++;
	while (redir[i] == ' ')
		i++;
	return (redir + i);
}

// int	open_out(char **redir, t_env *env)
// {
// 	t_utils	*u;

// 	u = init_utils();
// 	u->fd_tab = ft_malloc(sizeof(int) * cp_arr(redir), 0);
// 	while (redir && redir[u->i])
// 	{
// 		u->f_name = get_r_name(redir[u->i], env);
// 		u->f_name = get_f_name(u->f_name, env);
// 		if (redir[u->i][1] == '>')
// 			u->fd = open(u->f_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
// 		else
// 			u->fd = open(u->f_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		u->fd_tab[u->i] = u->fd;
// 		u->i ++;
// 		if (u->fd == -1)
// 			break ;
// 	}
// 	close_tab(u->fd_tab, u->i - 1);
// 	return (u->fd);
// }

// int	open_in(char **redir, t_env *env)
// {
// 	t_utils	*u;

// 	u = init_utils();
// 	u->fd_tab = ft_malloc(sizeof(int) * cp_arr(redir), 0);
// 	while (redir && redir[u->i])
// 	{
// 		u->f_name = get_r_name(redir[u->i], env);
// 		if (redir[u->i][1] == '<')
// 		{
// 			u->fd = open(u->f_name, O_RDONLY);
// 			unlink(u->f_name);
// 		}
// 		else
// 		{
// 			u->f_name = get_f_name(u->f_name, env);
// 			if (!u->f_name)
// 				return (-1);
// 			u->fd = open(u->f_name, O_RDONLY);
// 			if (u->fd == -1)
// 				printf("minishell:%s: No such file or directory\n", u->f_name);
// 		}
// 		u->fd_tab[u->i] = u->fd;
// 		u->i ++;
// 		if (u->fd == -1)
// 			break ;
// 	}
// 	close_tab(u->fd_tab, u->i - 1);
// 	return (u->fd);
// }

void	open_red(char **redir, int *fd_in, int *fd_out,t_env *env)
{
	t_utils	*u;

	u = init_utils(redir);
(void)env;
(void)fd_in;
(void)fd_out;


}