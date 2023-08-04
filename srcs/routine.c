/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:56:57 by bloisel           #+#    #+#             */
/*   Updated: 2023/07/13 18:40:46 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int check_print(t_philo *info)
{
// 	printf("No2\n");
// 	pthread_mutex_lock(&info->rout[0]);
// 	printf("yes %d\n", info->stop[0]);
	if (info->stop[0] == 1)
	{
// 		pthread_mutex_unlock(&info->rout[0]);
		return (1);
	}
// 	pthread_mutex_unlock(&info->rout[0]);
	return (0);
}

// void *is_thinking(t_philo *info)
// {
// 	if (check_print(info) == 0)
// 	{
// 		pthread_mutex_lock(&info->print[0]);
// 	}
// 	pthread_mutex_unlock(&info->print[0]);
// 	return NULL;
// }

void *is_sleeping(t_philo *info)
{
	// if (check_print(info) == 0) 
	// {
	// 		pthread_mutex_lock(&info->print[0]);
	printf("%lld , [%d] is sleeping\n", (timeval() - info->time_to_start) , info->id);
		// pthread_mutex_unlock(&info->print[0]);

	// }
	ft_usleep(info->time_to_sleep * 1000);
	// pthread_mutex_lock(&info->print[0]);
	printf("%lld , [%d] is thinking\n", (timeval() - info->time_to_start) , info->id);
	// pthread_mutex_unlock(&info->print[0]);
	return NULL;
}

void *is_eating(t_philo *info)
{
	// printf("No\n");
	// if (check_print(info) == 0)
	// {
	// 	pthread_mutex_lock(&info->print[0]);
		printf("%lld , [%d] is eating\n", (timeval() - info->time_to_start) , info->id);
	// 	pthread_mutex_unlock(&info->print[0]);

	// }
	// m_eat a voir plus tard
	ft_usleep(info->time_to_eat * 1000);	
	// info->last_eat[0] = timeval();
	// fonction unlock fork ? parcq manger est finit ? 
	// last eat vas etre modifer a ne pas oublier pour bien initialiser le temps ? 
	return NULL;
}

void *fork_test(t_philo *info)
{
		// if (info->id == info->nb_philo)
		// 	; forcement mourir car 1 fourchette 
		// printf("%d, %d  %d\n",info->id, info->right_fork, info->left_fork);
		pthread_mutex_lock(&info->fork[info->right_fork]);
		printf("%lld , [%d] has taken right_fork %d\n", (timeval() - info->time_to_start) , info->id, info->right_fork);
		pthread_mutex_lock(&info->fork[info->left_fork]);
		printf("%lld , [%d] has taken left_fork %d\n", (timeval() - info->time_to_start) , info->id, info->left_fork);
		is_eating(info);
		pthread_mutex_unlock(&info->fork[info->left_fork]);	
		pthread_mutex_unlock(&info->fork[info->right_fork]);
		info->last_eat[0] = timeval();
		return NULL;
}

void *thread_routine(void *philo_struct)
{
	t_philo *info;

	info = ((t_philo *)philo_struct);
	// pthread_mutex_unlock(&info->print[0]);
	// while (1)
	// {
		// if (check_print(info) == 1)
		// {
	if (info->id % 2 == 0)
		ft_usleep (info->time_to_eat * 1000);
	while (1)
	{
	// if (check_print(info) == 0)
	// 	{
		fork_test(info);
		is_sleeping(info);
		// }
	}
	return NULL;
}
