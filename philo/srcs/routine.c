/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:22:06 by trobert           #+#    #+#             */
/*   Updated: 2022/08/03 16:40:38 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	are_alive(t_philo *p)
{
	pthread_mutex_lock(&p->data->mutex_flag_dead);
	if (p->data->flag_dead == 1)
		return (pthread_mutex_unlock(&p->data->mutex_flag_dead), 0);
	pthread_mutex_unlock(&p->data->mutex_flag_dead);
	if (ft_abs(p->last_time_eat - (get_time() - p->start_time))
		>= p->data->time_die)
	{
		pthread_mutex_lock(&p->data->mutex_flag_dead);
		if (p->data->flag_dead == 1)
			return (pthread_mutex_unlock(&p->data->mutex_flag_dead), 0);
		p->data->flag_dead = 1;
		pthread_mutex_unlock(&p->data->mutex_flag_dead);
		display_msg(p, DYING, get_time() - p->start_time);
		return (0);
	}
	return (1);
}

void	eating(t_philo *p)
{
	if (are_alive(p))
	{
		pthread_mutex_lock(&p->data->mutex_check_forks);
		if (available_forks(p) == 2 && check_turn(p))
		{	
			pthread_mutex_unlock(&p->data->mutex_check_forks);
			take_forks(p);
			display_msg(p, EATING, get_time() - p->start_time);
			p->last_time_eat = get_time() - p->start_time;
			pthread_mutex_lock(&p->data->mutex_meals_tab);
			p->data->meals_tab[p->id]++;
			pthread_mutex_unlock(&p->data->mutex_meals_tab);
			if (usleep_function(p, p->data->time_eat) == -1)
				return ;
			put_forks(p);
			p->status = 1;
			return ;
		}
		pthread_mutex_unlock(&p->data->mutex_check_forks);
	}
}

void	sleeping(t_philo *p)
{
	if (are_alive(p))
	{
		display_msg(p, SLEEPING, get_time() - p->start_time);
		p->last_time_sleep = get_time() - p->start_time;
		if (usleep_function(p, p->data->time_sleep) == -1)
			return ;
		p->status = 2;
	}
}

void	thinking(t_philo *p)
{
	if (are_alive(p))
	{
		display_msg(p, THINKING, get_time() - p->start_time);
		p->last_time_think = get_time() - p->start_time;
		p->status = 0;
	}
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	if (check_begin(p))
	{
		pthread_mutex_lock(&p->data->mutex_time_begin);
		p->start_time = p->data->time_begin;
		pthread_mutex_unlock(&p->data->mutex_time_begin);
		while (are_alive(p) && count_meals_tab(p))
		{			
			if (p->status == 0)
				eating(p);
			if (p->status == 1)
				sleeping(p);
			if (p->status == 2)
				thinking(p);
			usleep(10);
		}
	}
	return ((void *)0);
}
