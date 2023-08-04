/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:55:48 by bloisel           #+#    #+#             */
/*   Updated: 2023/07/13 18:37:11 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int check_death(t_inf *info)
{
    int i = -1;
    
    while (++i < info->nb_philo) 
    {
		// printf("lock fisrt \n");
		// pthread_mutex_lock(&info->phiphi[i]->glob[0]);
		// printf("lock second\n");
        if (info->time_to_die < timeval() - info->phiphi[i]->last_eat[0])
            {
                printf("%lld [%d] is dead\n", timeval() - info->phiphi[i]->last_eat[0] , info->phiphi[i]->id);
                info->stop[0] = 1;
				// pthread_mutex_unlock(&info->phiphi[i]->glob[0]);
				// printf("ünlock first \n");
                return (1);
            }
        // else
		// 	{
        // 		pthread_mutex_unlock(&info->phiphi[i]->glob[0]);
		// 		printf("ünlock the second\n");
		// 	}
    }
    return (0);
}

void init_thread(t_inf *info)
{
	int i;
	pthread_t t[info->nb_philo];
	i = 0;
	while (i < info->nb_philo)
	{
		pthread_create(&t[i] , NULL , thread_routine , info->phiphi[i]);  
		i++;
		usleep(70);
	}
	i = 0;
	while(i < info->nb_philo)
	{
		pthread_detach(t[i]);
		i++;	
	}
	while (1)
	{
		usleep(200);
		if((check_death(info) == 1))
			return ;
	}
}