/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:11:09 by aherrero          #+#    #+#             */
/*   Updated: 2022/03/24 19:13:23 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->com->death);
	if ((int)(get_time() - philo->last_eat)
		>= philo->com->time_to_die)
	{
		if (philo->com->die == 0)
		{
			print_action(philo, 'd');
			philo->com->die = 1;
		}
	}
	pthread_mutex_unlock(&philo->com->death);
	return (philo->com->die);
}

void	print_action(t_philo *philo, char type)
{
	pthread_mutex_lock(&philo->com->print);
	if (type == 'e' && philo->com->die == 0)
		printf("%ld %d is eating\n",
			get_time() - philo->start, philo->philo_id + 1);
	else if (type == 's' && philo->com->die == 0)
		printf("%ld %d is sleeping\n",
			get_time() - philo->start, philo->philo_id + 1);
	else if (type == 't' && philo->com->die == 0)
		printf("%ld %d is thinking\n",
			get_time() - philo->start, philo->philo_id + 1);
	else if (type == 'd' && philo->com->die == 0)
		printf("%ld %d died\n",
			get_time() - philo->start, philo->philo_id + 1);
	else if (type == 'f' && philo->com->die == 0)
		printf("%ld %d has taken a fork\n",
			get_time() - philo->start, philo->philo_id + 1);
	pthread_mutex_unlock(&philo->com->print);
}

int	start_eat(t_philo	*philo)
{
	if (check_death(philo) == 1)
		return (2);
	if (philo->eat_times >= philo->com->n_eat && philo->com->n_eat > 0)
	{
		free_left_fork(philo);
		free_right_fork(philo);
		philo->com->eat -= 1;
		return (1);
	}
	if (philo->left == 1 && philo->right == 1 && philo->eating == 0)
	{
		print_action(philo, 'e');
		philo->eating = 1;
		philo->eat_times++;
		philo->thinking = 0;
		philo->eating_start = get_time();
		philo->last_eat = get_time();
	}
	return (0);
}

int	start_sleeping(t_philo *philo)
{
	if (check_death(philo) == 1)
		return (1);
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
	return (0);
}

int	start_thinking(t_philo *philo)
{
	if (check_death(philo) == 1)
		return (1);
	if (philo->sleeping == 1 && (get_time() - philo->sleeping_start)
		>= philo->com->time_to_sleep && philo->thinking == 0)
	{
		print_action(philo, 't');
		philo->sleeping = 0;
		philo->thinking = 1;
	}
	if (philo->thinking == 1)
	{
		if (check_death(philo) == 1)
			return (1);
		get_left_fork(philo);
		get_right_fork(philo);
	}
	return (0);
}
