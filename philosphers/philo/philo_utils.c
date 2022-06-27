/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:28:52 by aherrero          #+#    #+#             */
/*   Updated: 2022/04/08 16:27:00 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*philo_init_aux(t_philo	*philo)
{
	if ((philo->philo_id + 1) % 2 != 0)
	{
		get_right_fork(philo);
		get_left_fork(philo);
	}
	else
	{
		while (1)
		{
			if (philo->philo_id > 0)
			{
				if (philo->com->forks[philo->philo_id] == 1
					&& philo->com->forks[philo->philo_id - 1] == 1)
					break ;
			}
			else
				if (philo->com->forks[philo->philo_id] == 1
					&& philo->com->forks[philo->com->n_philo - 1] == 1)
					break ;
		}
	}
	return (philo);
}

t_philo	*philo_init(t_philo	*philo)
{
	philo->eating = 0;
	philo->eat_times = 0;
	philo->left = 0;
	philo->right = 0;
	philo->eating_start = 0;
	philo->sleeping = 0;
	philo->sleeping_start = 0;
	philo->thinking = 1;
	philo->thinking_start = 0;
	philo->last_eat = get_time();
	philo = philo_init_aux(philo);
	return (philo);
}

int	loop(t_philo *philo)
{
	check_death(philo);
	if (check_eats(philo) == 1)
		return (1);
	start_eat(philo);
	start_sleeping(philo);
	start_thinking(philo);
	return (0);
}

void	end(t_com *com)
{
	int	i;

	if (com->n_philo > 1)
		end_one(com);
	else
	{
		i = 0;
		if (pthread_join(com->tid[i], NULL) != 0)
			printf("JOIN OK -- %d\n", i);
		pthread_mutex_destroy(&com->mutex[i]);
	}
	pthread_mutex_destroy(&com->death);
	pthread_mutex_destroy(&com->print);
	free(com->forks);
	free(com->tid);
	free(com->mutex);
	free(com);
}

int	init_thread(t_com *com, t_philo *philo, int i)
{
	com->tid = malloc(sizeof(pthread_t) * com->n_philo);
	if (!com->tid)
	{
		free(com->forks);
		free(com->tid);
		free(com->mutex);
		free(com);
		return (0);
	}
	i = 0;
	pthread_mutex_init(&com->print, NULL);
	pthread_mutex_init(&com->death, NULL);
	while (i < com->n_philo)
	{
		philo = malloc(sizeof(t_philo));
		philo->com = com;
		philo->start = get_time();
		philo->philo_id = i;
		pthread_mutex_init(&com->mutex[i], NULL);
		if (pthread_create(&com->tid[i], NULL, thread, (void *)philo) != 0)
			printf("Failed creating thread\n");
		i++;
	}
	return (1);
}
