/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:22:06 by trobert           #+#    #+#             */
/*   Updated: 2022/08/03 15:25:27 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	available_forks(t_philo *p)
{
	int	count;

	count = 0;
	pthread_mutex_lock(&p->data->mutex_forks[p->id - 1]);
	if (p->data->forks[p->id - 1] == 0)
		count++;
	pthread_mutex_unlock(&p->data->mutex_forks[p->id - 1]);
	pthread_mutex_lock(&p->data->mutex_forks[p->id % p->data->nbr_philo]);
	if (p->data->forks[p->id % p->data->nbr_philo] == 0)
		count++;
	pthread_mutex_unlock(&p->data->mutex_forks[p->id % p->data->nbr_philo]);
	return (count);
}

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(&p->data->mutex_forks[p->id - 1]);
	p->data->forks[p->id - 1] = 1;
	pthread_mutex_unlock(&p->data->mutex_forks[p->id - 1]);
	pthread_mutex_lock(&p->data->mutex_forks[p->id % p->data->nbr_philo]);
	p->data->forks[p->id % p->data->nbr_philo] = 1;
	pthread_mutex_unlock(&p->data->mutex_forks[p->id % p->data->nbr_philo]);
}

void	put_forks(t_philo *p)
{
	pthread_mutex_lock(&p->data->mutex_forks[p->id - 1]);
	p->data->forks[p->id - 1] = 0;
	pthread_mutex_unlock(&p->data->mutex_forks[p->id - 1]);
	pthread_mutex_lock(&p->data->mutex_forks[p->id % p->data->nbr_philo]);
	p->data->forks[p->id % p->data->nbr_philo] = 0;
	pthread_mutex_unlock(&p->data->mutex_forks[p->id % p->data->nbr_philo]);
}
