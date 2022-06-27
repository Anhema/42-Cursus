/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:03:33 by aherrero          #+#    #+#             */
/*   Updated: 2022/04/08 17:23:31 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_one(void *val)
{
	t_philo	*philo;

	philo = (t_philo *)val;
	printf("%ld %d has taken a fork\n",
		get_time() - philo->start, philo->philo_id + 1);
	while ((int)(get_time() - philo->start) < philo->com->time_to_die)
		continue ;
	printf("%ld %d died\n",
		get_time() - philo->start, philo->philo_id + 1);
	free(philo);
	return (NULL);
}

int	init_thread_one(t_com *com, t_philo *philo)
{
	com->tid = malloc(sizeof(pthread_t));
	if (!com->tid)
	{
		free(com->forks);
		free(com->tid);
		free(com->mutex);
		free(com);
		return (0);
	}
	pthread_mutex_init(&com->print, NULL);
	pthread_mutex_init(&com->death, NULL);
	philo = malloc(sizeof(t_philo));
	philo->com = com;
	philo->start = get_time();
	philo->philo_id = 0;
	pthread_mutex_init(&com->mutex[0], NULL);
	if (pthread_create(&com->tid[0], NULL, thread_one, (void *)philo) != 0)
		printf("Failed creating thread\n");
	return (1);
}

void	end_one(t_com *com)
{
	int	i;

	i = 0;
	while (i < com->n_philo)
	{
		if (!com->tid[i])
			break ;
		if (pthread_join(com->tid[i], NULL) != 0)
			printf("JOIN OK -- %d\n", i);
		i++;
	}
	i = 0;
	while (i < com->n_philo)
	{
		pthread_mutex_destroy(&com->mutex[i]);
		i++;
	}
}

int	check_eats(t_philo *philo)
{
	check_death(philo);
	if (philo->eat_times >= philo->com->n_eat && philo->com->n_eat > 0)
	{
		free_left_fork(philo);
		free_right_fork(philo);
		philo->com->eat -= 1;
		return (1);
	}
	return (0);
}
