/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:44:57 by trobert           #+#    #+#             */
/*   Updated: 2022/08/03 15:39:40 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H 

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h> 
# include <string.h>
# include <sys/time.h>
# include <errno.h>

enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	DYING
};

typedef struct s_data
{
	struct timeval	time;
	pthread_mutex_t	mutex_flag_dead;
	pthread_mutex_t	mutex_flag_begin;
	pthread_mutex_t	mutex_time_begin;
	pthread_mutex_t	mutex_check_turn;
	pthread_mutex_t	mutex_check_forks;
	pthread_mutex_t	mutex_meals_tab;
	pthread_mutex_t	mutex_msgs;
	pthread_mutex_t	*mutex_forks;
	pthread_t		*thread;
	int				*meals_tab;
	int				*order_tab;
	int				*forks;
	int				flag_dead;
	int				flag_begin;
	int				time_begin;
	int				turn_index;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	int				min_meals;
	int				nbr_philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				status;
	int				start_time;
	int				last_time_eat;
	int				last_time_sleep;
	int				last_time_think;
	t_data			*data;
}	t_philo;

////////////////////////////////////// LIBFT UTILS FUNCTIONS ///////////////////

int			ft_strlen(char *str);
int			ft_abs(int x);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
int			get_smaller_nbr(int *tab, t_philo *p);

///////////////////////////////////// INIT AND PARSING FUNCTIONS //////////////

int			is_digit_or_sign(int argc, char **argv);
int			is_args_valid(int argc, char **argv);

void		put_order_tab(int *tab, int nbr);
void		init_philo(t_philo *philo, t_data *data, int i);
int			init_data(t_philo *p, t_data *data);
int			init_var(t_philo *p, t_data *data, char **argv, int argc);
void		init_mutex(t_philo *p);

/////////////////////////////////// THREADS & ROUTINE FUNCTIONS ///////////////

int			philo(t_philo *p);
int			create_threads(t_philo *p);

void		*routine(void *philo);
void		eating(t_philo *p);
void		sleeping(t_philo *p);
void		thinking(t_philo *p);
int			are_alive(t_philo *p);

int			check_begin(t_philo *p);
int			check_turn(t_philo *p);
int			count_meals_tab(t_philo *p);

int			available_forks(t_philo *p);
void		take_forks(t_philo *p);
void		put_forks(t_philo *p);

int			usleep_function(t_philo *p, int time);
int			get_time(void);
void		display_msg(t_philo *p, enum e_status status, long tstamp);

//////////////////////////////// ERROR FREE & QUIT FUNCTIONS ///////////////////

void		destroy_mutex(t_philo *p);
int			error_quit(char *str);
int			free_split(char **tab);
int			free_all(t_philo *p);

#endif
