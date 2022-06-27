/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:28:52 by aherrero          #+#    #+#             */
/*   Updated: 2022/04/07 19:37:03 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*philo_init_aux(t_philo	*philo)
{
	if ((philo->philo_id + 1) % 2 != 0)
	{
		get_right_fork(philo);
		get_left_fork(philo);
	}
	else
		usleep(500);
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
	if (philo->com->n_philo == 1)
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
	usleep(philo->com->time_to_eat * 1000);
	start_sleeping(philo);
	start_thinking(philo);
	return (0);
}

void	end(t_com *com)
{
	sem_close(com->forks);
	sem_close(com->print);
	sem_close(com->death);
	free(com->pid);
	free(com);
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
