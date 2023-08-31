/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:28:08 by trobert           #+#    #+#             */
/*   Updated: 2022/08/03 15:25:55 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_abs(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != 0)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}

int	get_smaller_nbr(int *tab, t_philo *p)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 1;
	while (++i < p->data->nbr_philo + 1)
	{
		j = i + 1;
		while (j < p->data->nbr_philo + 1)
		{
			if (tab[j] < tab[i] && tab[j] < tab[index])
				index = j;
			j++;
		}
	}
	return (index);
}
