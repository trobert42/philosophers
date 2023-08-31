/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:26:57 by trobert           #+#    #+#             */
/*   Updated: 2023/05/01 16:59:35 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_len_argv(int argc, char **argv)
{
	int	i;
	int	len;

	i = 0;
	while (++i < argc)
	{
		len = ft_strlen(argv[i]);
		if (i != 2 && len > 6)
			return (printf("arg too high, u don't want to wait that long\n"), 0);
	}
	return (1);
}

int	is_digit_or_sign(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		len = ft_strlen(argv[i]);
		if (len == 0)
			return (0);
		while (++j < len)
		{
			if (j == 0 && argv[i][0] != '+')
			{
				if (!(argv[i][0] >= '0' && argv[i][0] <= '9'))
					return (0);
			}
			else if (len == 1 && (argv[i][0] == '+' || argv[i][0] == '-'))
				return (0);
			else if (j != 0 && (argv[i][j] < '0' || argv[i][j] > '9'))
				return (0);
		}
	}
	return (1);
}

int	is_args_valid(int argc, char **argv)
{
	if (argc < 5 || argc > 6 || is_digit_or_sign(argc, argv) == 0)
		return (printf("Error, nbr of args isn't valid\n"), 0);
	if (check_len_argv(argc, argv) == 0)
		return (0);
	if (ft_atoi(argv[1]) < 2)
	{
		if (ft_atoi(argv[1]) == 1)
			printf("One philosopher can't eat with only one fork :(\n");
		else
			printf("Need at least 2 philo\n");
		return (0);
	}
	if (ft_atoi(argv[1]) > 200)
		return (printf("Too much philo\n"), 0);
	if (ft_atoi(argv[3]) < 1)
		return (printf("They need to eat\n"), 0);
	return (1);
}
