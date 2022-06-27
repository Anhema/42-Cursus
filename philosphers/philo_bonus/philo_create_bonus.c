/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:32:03 by aherrero          #+#    #+#             */
/*   Updated: 2022/04/04 16:17:23 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_death_routine(void *var)
{
	t_philo	*philo;

	philo = var;
	while (1)
	{
		usleep(100);
		check_death(philo);
	}
}

int	init_proc(int pid, t_com *com, int i)
{
	t_philo				*philo;

	pid = fork();
	if (pid == 0)
	{
		philo = malloc(sizeof(t_philo));
		philo->com = com;
		philo->start = com->start;
		philo->philo_id = i;
		pthread_create(&philo->death, NULL, ft_death_routine, philo);
		proc(philo);
		return (1);
	}
	else
		com->pid[i] = pid;
	return (0);
}
