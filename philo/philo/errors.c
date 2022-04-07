/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:11:51 by aherrero          #+#    #+#             */
/*   Updated: 2022/03/24 18:58:11 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	errors(t_com *com, int argc)
{
	if (com->n_philo <= 0)
		return (0);
	if (com->time_to_die <= 0)
		return (0);
	if (com->time_to_eat <= 0)
		return (0);
	if (com->time_to_sleep <= 0)
		return (0);
	if (argc == 6)
		if (com->n_eat < 0)
			return (0);
	return (1);
}

t_com	*check_valid_input(int argc, char **argv)
{
	t_com		*com;

	com = NULL;
	if (argc < 5 || argc > 6)
	{
		printf("\033[0;31mInvlid format: \033[0m");
		printf("./philo [n_philosophers] [t_die] [t_eat] [t_sleep] [n_eat]\n");
		return (NULL);
	}
	com = malloc(sizeof(t_com));
	if (!com)
		return (NULL);
	com = fill_basic(argc, argv, com);
	if (errors(com, argc) == 0 || !com->mutex)
	{
		printf("Invalid input\n");
		if (com->mutex)
			free(com->mutex);
		free (com);
		return (NULL);
	}
	return (com);
}
