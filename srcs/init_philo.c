/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:56:46 by bloisel           #+#    #+#             */
/*   Updated: 2023/06/29 17:05:37 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

void init_phiphi(t_inf *info)
{
	int i;

	i = -1;
	while (++i < info->nb_philo)
	{
		info->phiphi[i]->id = i + 1;
		info->phiphi[i]->nb_philo = info->nb_philo;
		info->phiphi[i]->time_to_die = info->time_to_die;
		info->phiphi[i]->time_to_eat = info->time_to_eat;
		info->phiphi[i]->time_to_sleep = info->time_to_sleep;
		info->phiphi[i]->fork = &info->fork[i];
		info->phiphi[i]->last_eat[0] = timeval();
		info->phiphi[i]->stop = info->stop;
		info->phiphi[i]->print = info->print; // pointeur de mutex qui devait etree present dans chaque struct de philo 
		info->phiphi[i]->glob = info->glob;
		info->phiphi[i]->rout = info->rout;
		info->phiphi[i]->time_to_start = info->time_to_start;
		if (info->phiphi[i]->id == info->nb_philo)
			info->phiphi[i]->right_fork = 0;
		else
			info->phiphi[i]->right_fork = i + 1;
		info->phiphi[i]->left_fork = i;
	}
}

void init_philo(t_inf *info)
{
	int i;

	info->phiphi = malloc(sizeof(t_philo*) * info->nb_philo);
	i = -1;
	while (++i < info->nb_philo)
	{
		info->phiphi[i] = malloc(sizeof(t_philo));
		info->phiphi[i]->last_eat = malloc(sizeof(time_t));
	}
	init_phiphi(info);
}