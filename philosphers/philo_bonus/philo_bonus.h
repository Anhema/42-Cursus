/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:45:01 by aherrero          #+#    #+#             */
/*   Updated: 2022/04/01 16:37:34 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>
# include <time.h>
# include <stdlib.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>
# include <sys/wait.h>

typedef struct common
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_eat;
	int				eat;
	long			start;
	int				die;
	int				*pid;
	sem_t			*forks;
	sem_t			*death;
	sem_t			*print;
}				t_com;

typedef struct s_philo {
	long			start;
	int				left;
	int				right;
	int				eating;
	int				eat_times;
	int				sleeping;
	long			sleeping_start;
	int				thinking;
	long			thinking_start;
	long			eating_start;
	long			last_eat;
	int				philo_id;
	pthread_t		death;
	t_com			*com;
}				t_philo;

int		errors(t_com *com, int argc);
t_com	*check_valid_input(int argc, char **argv);
int		is_num(char *str);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
long	get_time(void);
t_com	*fill_basic(int argc, char **argv, t_com *com);
void	*ft_death_routine(void *var);
int		init_proc(int pid, t_com *com, int i);
void	proc(t_philo *philo);
int		loop(t_philo *philo);
void	check_death(t_philo *philo);
void	print_action(t_philo *philo, char type);
int		check_eats(t_philo	*philo);
void	start_eat(t_philo	*philo);
void	start_sleeping(t_philo *philo);
void	start_thinking(t_philo *philo);
void	get_left_fork(t_philo *philo);
void	get_right_fork(t_philo *philo);
void	free_left_fork(t_philo *philo);
void	free_right_fork(t_philo *philo);
t_philo	*philo_init(t_philo	*philo);
void	end(t_com *com);

#endif