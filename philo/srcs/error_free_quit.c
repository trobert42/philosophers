/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_quit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:28:08 by trobert           #+#    #+#             */
/*   Updated: 2022/08/03 15:26:02 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_mutex(t_philo *p)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&p->data->mutex_msgs);
	pthread_mutex_destroy(&p->data->mutex_check_forks);
	pthread_mutex_destroy(&p->data->mutex_check_turn);
	pthread_mutex_destroy(&p->data->mutex_meals_tab);
	pthread_mutex_destroy(&p->data->mutex_time_begin);
	pthread_mutex_destroy(&p->data->mutex_flag_begin);
	pthread_mutex_destroy(&p->data->mutex_flag_dead);
	while (++i < p->data->nbr_philo)
		pthread_mutex_destroy(&p->data->mutex_forks[i]);
}

int	error_quit(char *str)
{
	printf("%s\n", str);
	return (-1);
}

int	free_all(t_philo *p)
{
	if (p->data->order_tab)
		free(p->data->order_tab);
	if (p->data->meals_tab)
		free(p->data->meals_tab);
	if (p->data->forks)
		free(p->data->forks);
	if (p->data->mutex_forks)
		free(p->data->mutex_forks);
	if (p->data->thread)
		free(p->data->thread);
	if (p->data)
		free(p->data);
	if (p)
		free(p);
	return (0);
}
