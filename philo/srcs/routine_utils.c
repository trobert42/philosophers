/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:28:08 by trobert           #+#    #+#             */
/*   Updated: 2022/08/04 17:15:28 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	usleep_function(t_philo *p, int time)
{
	int	start;

	start = get_time();
	while (get_time() - start < time)
	{
		usleep(100);
		if (!are_alive(p))
			return (-1);
	}		
	return (1);
}

int	get_time(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return (start.tv_sec * 1000 + start.tv_usec / 1000);
}

void	display_msg(t_philo *p, enum e_status status, long tstamp)
{
	pthread_mutex_lock(&p->data->mutex_msgs);
	if (count_meals_tab(p))
	{
		if (status == EATING)
		{
			printf("%ld %d has taken a fork\n", tstamp, p->id);
			printf("%ld %d has taken a fork\n", tstamp, p->id);
			printf("%ld %d is eating\n", tstamp, p->id);
		}
		else if (status == SLEEPING)
			printf("%ld %d is sleeping\n", tstamp, p->id);
		else if (status == THINKING)
			printf("%ld %d is thinking\n", tstamp, p->id);
		else if (status == DYING)
			printf("%ld %d died\n", tstamp, p->id);
	}
	pthread_mutex_unlock(&p->data->mutex_msgs);
}
      