/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:43:50 by aherrero          #+#    #+#             */
/*   Updated: 2022/04/01 16:40:38 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_com	*fill_basic_aux( char **argv, t_com *com)
{
	if (ft_atoi(argv[1]) > 0 && is_num(argv[1]) == 1)
		com->n_philo = ft_atoi(argv[1]);
	else
		com->n_philo = -1;
	if (ft_atoi(argv[2]) && is_num(argv[2]) == 1)
		com->time_to_die = ft_atoi(argv[2]);
	else
		com->time_to_die = -1;
	if (ft_atoi(argv[3]) && is_num(argv[3]) == 1)
		com->time_to_eat = ft_atoi(argv[3]);
	else
		com->time_to_eat = -1;
	if (ft_atoi(argv[4]) && is_num(argv[4]) == 1)
		com->time_to_sleep = ft_atoi(argv[4]);
	else
		com->time_to_sleep = -1;
	return (com);
}

t_com	*fill_basic(int argc, char **argv, t_com *com)
{
	com = fill_basic_aux(argv, com);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) && is_num(argv[5]) == 1)
			com->n_eat = ft_atoi(argv[5]);
		else
			com->n_eat = -1;
	}
	else
		com->n_eat = -1;
	com->die = 0;
	if (com->n_philo <= 0)
		return (com);
	sem_unlink("/forks");
	com->forks = sem_open("/forks", O_CREAT, 0, com->n_philo);
	sem_unlink("/death");
	com->death = sem_open("/death", O_CREAT, 0, 1);
	sem_unlink("/print");
	com->print = sem_open("/print", O_CREAT, 0, 1);
	return (com);
}

void	proc(t_philo *philo)
{
	int		_loop;

	philo = philo_init(philo);
	while (philo->com->die == 0)
	{
		_loop = loop(philo);
		if (_loop == 1)
			break ;
	}
	while (philo->com->n_eat > 0)
	{
		if (philo->com->eat <= 0)
		{
			free(philo);
			exit (1);
		}
	}
	free(philo);
	exit (1);
}

void	ft_wait_procs(t_com *com)
{
	int	i;
	int	y;
	int	status;

	i = 0;
	while (i < com->n_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			y = 0;
			while (y < com->n_philo)
			{
				kill(com->pid[y], SIGKILL);
				y++;
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_com				*com;
	int					i;
	int					pid;
	int					forks;

	com = check_valid_input(argc, argv);
	if (!com)
		return (0);
	i = 0;
	pid = 1;
	forks = com->n_philo;
	com->pid = malloc(sizeof(int) * com->n_philo);
	com->start = get_time();
	while (i < com->n_philo)
	{
		if (init_proc(pid, com, i) == 1)
			break ;
		i++;
	}
	ft_wait_procs(com);
	end(com);
	return (0);
}
