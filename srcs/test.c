/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:57:05 by bloisel           #+#    #+#             */
/*   Updated: 2023/06/29 16:57:09 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

#define NB_P 2

void try_other(t_inf *info)
{
    int i = -1;
    while(++i < NB_P)
    {
        printf("%d\n", info->phiphi[i]->time_to_eat);
        info->phiphi[i]->time_to_eat++;
        printf("%d\n", info->phiphi[i]->time_to_eat); 
    }
}

void try_struct(t_inf *info)
{
    int i = 0;
    info->phiphi = malloc(sizeof(t_philo*) * info->nb_philo);
    while (i < NB_P)
    {
    info->phiphi[i] = malloc(sizeof(t_philo));
    info->phiphi[i]->time_to_eat = info->time_to_eat;
    i++;
    }
    try_other(info);
}

int main()
{
    t_inf info;
    info.time_to_die = 200;
    info.time_to_eat = 50;
    info.nb_philo = NB_P;
    info.phiphi = NULL;
    try_struct(&info);
    printf("main %d\n",info.time_to_eat);
}