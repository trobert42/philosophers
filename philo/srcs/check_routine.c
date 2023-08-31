/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:22:06 by trobert           #+#    #+#             */
/*   Updated: 2022/08/03 15:25:25 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_begin(t_philo *p)
{
	if (p->id == p->data->nbr_philo)
	{
		pthread_mutex_lock(&p->data->mutex_time_begin);
		p->data->time_begin = get_time();
		pthread_mutex_unlock(&p->data->mutex_time_begin);
		pthread_mutex_lock(&p->data->mutex_flag_begin);
		p->data->flag_begin = 1;
		pthread_mutex_unlock(&p->data->mutex_flag_begin);
	}
	while (1)
	{
		pthread_mutex_lock(&p->data->mutex_flag_begin);
		if (p->data->flag_begin)
		{
			pthread_mutex_unlock(&p->data->mutex_flag_begin);
			return (1);
		}
		pthread_mutex_unlock(&p->data->mutex_flag_begin);
		usleep(50);
	}
}

int	check_turn(t_philo *p)
{
	pthread_mutex_lock(&p->data->mutex_check_turn);
	if (p->id == p->data->order_tab[p->data->turn_index])
	{
		p->data->turn_index++;
		if (p->data->turn_index == p->data->nbr_philo)
			p->data->turn_index = 0;
		pthread_mutex_unlock(&p->data->mutex_check_turn);
		return (1);
	}
	pthread_mutex_unlock(&p->data->mutex_check_turn);
	return (0);
}

int	count_meals_tab(t_philo *p)
{
	int	index;

	if (p->data->min_meals != -1)
	{
		pthread_mutex_lock(&p->data->mutex_meals_tab);
		index = get_smaller_nbr(p->data->meals_tab, p);
		if (p->data->meals_tab[index] == p->data->min_meals)
		{
			pthread_mutex_unlock(&p->data->mutex_meals_tab);
			return (0);
		}
		pthread_mutex_unlock(&p->data->mutex_meals_tab);
	}
	return (1);
}
