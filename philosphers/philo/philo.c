/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:55:53 by aherrero          #+#    #+#             */
/*   Updated: 2022/04/08 17:04:39 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	com->mutex = NULL;
	if (com->n_philo <= 0)
		return (com);
	else if (com->n_philo == 1)
		com->mutex = (pthread_mutex_t *)malloc(
				sizeof(pthread_mutex_t));
	else
		com->mutex = (pthread_mutex_t *)malloc(
				sizeof(pthread_mutex_t) * com->n_philo);
	return (com);
}

static int	create_forks(t_com *com)
{
	int	i;

	i = 0;
	com->forks = (int *)malloc(sizeof(int) * com->n_philo);
	if (!com->forks)
	{
		free(com->mutex);
		free(com->tid);
		free(com->forks);
		free (com);
		return (0);
	}
	i = 0;
	while (i != com->n_philo)
	{
		com->forks[i] = 0;
		i++;
	}
	return (1);
}

void	*thread(void *val)
{
	t_philo	*philo;
	int		_loop;

	philo = (t_philo *)val;
	philo = philo_init(philo);
	while (philo->com->die == 0)
	{
		check_death(philo);
		_loop = loop(philo);
		if (_loop == 1)
			break ;
		ft_usleep(1);
	}
	while (philo->com->n_eat > 0)
	{
		if (philo->com->eat <= 0)
		{
			free(philo);
			return (NULL);
		}
	}
	free(philo);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_com		*com;
	t_philo		*philo;
	int			i;

	com = check_valid_input(argc, argv);
	if (!com)
		return (0);
	if (create_forks(com) == 0)
		return (0);
	philo = NULL;
	com->eat = ft_atoi(argv[1]);
	i = 0;
	if (com->n_philo > 1)
	{
		if (init_thread(com, philo, i) == 0)
			return (0);
	}
	else
	{
		if (init_thread_one(com, philo) == 0)
			return (0);
	}
	end(com);
	return (0);
}
