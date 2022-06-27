/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:55:53 by aherrero          #+#    #+#             */
/*   Updated: 2022/04/07 22:20:08 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>
# include <time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct common
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_eat;
	int				eat;
	int				*forks;
	long			start;
	int				die;
	pthread_t		*tid;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	*mutex;
}				t_com;

typedef struct s_philo {
	long	start;
	int		left;
	int		right;
	int		eating;
	int		eat_times;
	int		sleeping;
	long	sleeping_start;
	int		thinking;
	long	thinking_start;
	long	eating_start;
	long	last_eat;
	int		philo_id;
	t_com	*com;
}				t_philo;

int		is_num(char *str);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		errors(t_com *com, int argc);
t_com	*check_valid_input(int argc, char **argv);
t_com	*fill_basic(int argc, char **argv, t_com *com);
long	get_time(void);
void	get_left_fork(t_philo *philo);
void	get_right_fork(t_philo *philo);
void	free_left_fork(t_philo *philo);
void	free_right_fork(t_philo *philo);
int		init_thread(t_com *com, t_philo *philo, int i);
int		init_thread_one(t_com *com, t_philo *philo);
t_philo	*philo_init(t_philo	*philo);
void	*thread(void *val);
void	*thread_one(void *val);
int		loop(t_philo *philo);
void	check_death(t_philo *philo);
void	start_eat(t_philo	*philo);
void	start_sleeping(t_philo *philo);
void	start_thinking(t_philo *philo);
void	print_action(t_philo *philo, char type);
void	end(t_com *com);
void	end_one(t_com *com);
void	ft_usleep(int minlisec);
int		check_eats(t_philo *philo);

#endif