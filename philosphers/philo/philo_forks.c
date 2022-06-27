/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:08:58 by aherrero          #+#    #+#             */
/*   Updated: 2022/03/23 19:00:39 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_left_fork_aux(t_philo *philo)
{
	if (philo->philo_id == 0)
	{
		if (philo->com->forks[philo->com->n_philo - 1] == 0)
		{
			philo->left = 1;
			philo->com->forks[philo->com->n_philo - 1] = 1;
			print_action(philo, 'f');
		}
	}
	else
	{
		if (philo->com->forks[philo->philo_id - 1] == 0)
		{
			philo->left = 1;
			philo->com->forks[philo->philo_id - 1] = 1;
			print_action(philo, 'f');
		}
	}
}

void	get_left_fork(t_philo *philo)
{
	if (philo->philo_id <= 0)
		pthread_mutex_lock(&philo->com->mutex[philo->com->n_philo - 1]);
	else
		pthread_mutex_lock(&philo->com->mutex[philo->philo_id - 1]);
	get_left_fork_aux(philo);
	if (philo->philo_id <= 0)
		pthread_mutex_unlock(&philo->com->mutex[philo->com->n_philo - 1]);
	else
		pthread_mutex_unlock(&philo->com->mutex[philo->philo_id - 1]);
}

void	get_right_fork(t_philo *philo)
{	
	pthread_mutex_lock(&philo->com->mutex[philo->philo_id]);
	if (philo->com->forks[philo->philo_id] == 0)
	{
		philo->right = 1;
		philo->com->forks[philo->philo_id] = 1;
		print_action(philo, 'f');
	}
	pthread_mutex_unlock(&philo->com->mutex[philo->philo_id]);
}

void	free_left_fork(t_philo *philo)
{
	if (philo->philo_id <= 0)
		pthread_mutex_lock(&philo->com->mutex[philo->com->n_philo - 1]);
	else
		pthread_mutex_lock(&philo->com->mutex[philo->philo_id - 1]);
	if (philo->philo_id == 0)
	{
		if (philo->com->forks[philo->com->n_philo - 1] == 1)
		{
			philo->left = 0;
			philo->com->forks[philo->com->n_philo - 1] = 0;
		}
	}
	else
	{
		if (philo->com->forks[philo->philo_id - 1] == 1)
		{
			philo->left = 0;
			philo->com->forks[philo->philo_id - 1] = 0;
		}
	}
	if (philo->philo_id <= 0)
		pthread_mutex_unlock(&philo->com->mutex[philo->com->n_philo - 1]);
	else
		pthread_mutex_unlock(&philo->com->mutex[philo->philo_id - 1]);
}

void	free_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->com->mutex[philo->philo_id]);
	if (philo->com->forks[philo->philo_id] == 1)
	{
		philo->right = 0;
		philo->com->forks[philo->philo_id] = 0;
	}
	pthread_mutex_unlock(&philo->com->mutex[philo->philo_id]);
}
