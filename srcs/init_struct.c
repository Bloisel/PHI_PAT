/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:56:41 by bloisel           #+#    #+#             */
/*   Updated: 2023/06/29 16:56:44 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void init_mutex(t_inf *info)
{
	int i;

	i = 0;
	while (i < info->nb_philo)
	{
		pthread_mutex_init(&info->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&info->print[0], NULL);
	pthread_mutex_init(&info->glob[0], NULL);
	pthread_mutex_init(&info->rout[0], NULL);
}

void	init_struct(t_inf *info, char **argv)
{
	info->nb_philo = ft_atoi_s(argv[1]);
	info->time_to_die = ft_atoi_s(argv[2]);
	info->time_to_eat = ft_atoi_s(argv[3]);
	info->time_to_sleep = ft_atoi_s(argv[4]);
	info->time_to_start = timeval();
	if (argv[5] == 0)
		info->nb_m_eat = 0;
	info->stop = malloc(sizeof(int));
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nb_philo);
	info->print = malloc(sizeof(pthread_mutex_t));
	info->glob = malloc(sizeof(pthread_mutex_t));
	info->rout = malloc(sizeof(pthread_mutex_t));
	info->stop[0] = 0;
	init_mutex(info);
}