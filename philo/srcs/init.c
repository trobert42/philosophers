/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:22:06 by trobert           #+#    #+#             */
/*   Updated: 2022/08/03 15:25:28 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	put_order_tab(int *tab, int nbr)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < nbr)
	{
		while (i % 2 == 1 && i < nbr + 1)
		{
			tab[j++] = i;
			i += 2;
		}
		i = 2;
		while (i % 2 == 0 && i < nbr + 1)
		{
			tab[j++] = i;
			i += 2;
		}
	}
	tab[j] = 0;
}

void	init_philo(t_philo *philo, t_data *data, int i)
{
	int	j;

	j = -1;
	while (++j < data->nbr_philo)
		data->forks[j] = 0;
	philo->id = i + 1;
	philo->status = 0;
	philo->last_time_eat = 0;
	philo->last_time_sleep = 0;
	philo->last_time_think = 0;
	philo->data = data;
}

int	init_data(t_philo *p, t_data *data)
{
	int	i;

	i = -1;
	data->thread = malloc(sizeof(pthread_t *) * data->nbr_philo);
	if (!data->thread)
		return (-1);
	data->forks = malloc(sizeof(int) * data->nbr_philo);
	if (!data->forks)
		return (-1);
	while (++i < data->nbr_philo)
		init_philo(&p[i], data, i);
	data->mutex_forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	if (!data->mutex_forks)
		return (-1);
	data->order_tab = malloc(sizeof(int) * (data->nbr_philo + 1));
	if (!data->order_tab)
		return (-1);
	data->meals_tab = malloc(sizeof(int) * (data->nbr_philo + 1));
	if (!data->meals_tab)
		return (-1);
	i = -1;
	while (++i < data->nbr_philo + 1)
		data->meals_tab[i] = 0;
	return (0);
}

int	init_var(t_philo *p, t_data *data, char **argv, int argc)
{
	data->thread = NULL;
	data->forks = NULL;
	data->mutex_forks = NULL;
	data->order_tab = NULL;
	data->meals_tab = NULL;
	data->flag_dead = 0;
	data->flag_begin = 0;
	data->turn_index = 0;
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->min_meals = ft_atoi(argv[5]);
	else
		data->min_meals = -1;
	if (init_data(p, data) == -1)
		return (-1);
	put_order_tab(data->order_tab, data->nbr_philo);
	return (0);
}

void	init_mutex(t_philo *p)
{
	int	i;

	i = -1;
	pthread_mutex_init(&p->data->mutex_msgs, NULL);
	pthread_mutex_init(&p->data->mutex_check_forks, NULL);
	pthread_mutex_init(&p->data->mutex_meals_tab, NULL);
	pthread_mutex_init(&p->data->mutex_check_turn, NULL);
	pthread_mutex_init(&p->data->mutex_time_begin, NULL);
	pthread_mutex_init(&p->data->mutex_flag_begin, NULL);
	pthread_mutex_init(&p->data->mutex_flag_dead, NULL);
	while (++i < p->data->nbr_philo)
		pthread_mutex_init(&p->data->mutex_forks[i], NULL);
}
