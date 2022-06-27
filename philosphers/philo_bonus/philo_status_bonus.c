/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:11:09 by aherrero          #+#    #+#             */
/*   Updated: 2022/04/01 19:12:26 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_death(t_philo *philo)
{
	sem_wait(philo->com->death);
	if ((int)(get_time() - philo->last_eat)
		>= philo->com->time_to_die)
	{
		print_action(philo, 'd');
		sem_wait(philo->com->print);
		free(philo);
		exit (1);
	}
	if (philo->com->n_eat > 0
		&& philo->eat_times == (philo->com->n_eat + 1))
	{
		pthread_join(philo->death, NULL);
		exit(1);
	}
	sem_post(philo->com->death);
}

void	print_action(t_philo *philo, char type)
{
	sem_wait(philo->com->print);
	if (type == 'e')
		printf("%ld %d is eating\n",
			get_time() - philo->start, philo->philo_id + 1);
	else if (type == 's')
		printf("%ld %d is sleeping\n",
			get_time() - philo->start, philo->philo_id + 1);
	else if (type == 't')
		printf("%ld %d is thinking\n",
			get_time() - philo->start, philo->philo_id + 1);
	else if (type == 'd')
		printf("%ld %d died\n",
			get_time() - philo->start, philo->philo_id + 1);
	else if (type == 'f')
		printf("%ld %d has taken a fork\n",
			get_time() - philo->start, philo->philo_id + 1);
	sem_post(philo->com->print);
}

void	start_eat(t_philo	*philo)
{
	check_death(philo);
	if (philo->left == 1 && philo->right == 1 && philo->eating == 0)
	{
		print_action(philo, 'e');
		philo->eating = 1;
		philo->eat_times++;
		philo->thinking = 0;
		philo->last_eat = get_time();
		philo->eating_start = get_time();
	}
}

void	start_sleeping(t_philo *philo)
{
	check_death(philo);
	if (philo->eating == 1 && (get_time() - philo->eating_start)
		>= philo->com->time_to_eat && philo->sleeping == 0)
	{
		print_action(philo, 's');
		philo->eating = 0;
		free_left_fork(philo);
		free_right_fork(philo);
		philo->sleeping = 1;
		philo->sleeping_start = get_time();
	}
}

void	start_thinking(t_philo *philo)
{
	check_death(philo);
	if (philo->sleeping == 1 && (get_time() - philo->sleeping_start)
		>= philo->com->time_to_sleep && philo->thinking == 0)
	{
		print_action(philo, 't');
		philo->sleeping = 0;
		philo->thinking = 1;
	}
	if (philo->thinking == 1)
	{
		check_death(philo);
		get_left_fork(philo);
		get_right_fork(philo);
	}
}
