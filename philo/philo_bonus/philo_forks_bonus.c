/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:08:58 by aherrero          #+#    #+#             */
/*   Updated: 2022/04/01 16:07:35 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	get_left_fork(t_philo *philo)
{
	check_death(philo);
	sem_wait(philo->com->forks);
	philo->left = 1;
	print_action(philo, 'f');
	check_death(philo);
}

void	get_right_fork(t_philo *philo)
{	
	check_death(philo);
	sem_wait(philo->com->forks);
	philo->right = 1;
	print_action(philo, 'f');
	check_death(philo);
}

void	free_left_fork(t_philo *philo)
{
	philo->left = 0;
	sem_post(philo->com->forks);
}

void	free_right_fork(t_philo *philo)
{
	philo->right = 0;
	sem_post(philo->com->forks);
}
