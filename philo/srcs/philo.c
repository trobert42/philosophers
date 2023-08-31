/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:22:06 by trobert           #+#    #+#             */
/*   Updated: 2022/08/03 15:25:31 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_threads(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->data->nbr_philo)
	{
		if (pthread_create(&p->data->thread[i], NULL, &routine, &p[i]))
			return (error_quit("Failed to create a thread"));
	}
	i = -1;
	while (++i < p->data->nbr_philo)
	{
		if (pthread_join(p->data->thread[i], NULL) != 0)
			return (error_quit("Failed to join threads"));
	}
	return (0);
}

int	philo(t_philo *p)
{
	init_mutex(p);
	if (create_threads(p) == -1)
		return (-1);
	destroy_mutex(p);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*p;
	t_data	*data;

	p = NULL;
	data = NULL;
	if (is_args_valid(argc, argv) == 0)
		return (0);
	p = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!p)
		return (printf("malloc of p has failed\n"), 0);
	data = malloc(sizeof(t_data));
	if (!data)
	{
		free(p);
		return (printf("malloc of data has failed\n"), 0);
	}
	if (init_var(p, data, argv, argc) == -1 || philo(p) == -1)
		return (free_all(p));
	return (free_all(p));
}
