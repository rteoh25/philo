/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:02:48 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/26 11:05:42 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_life *life)
{
	if (pthread_mutex_init(&life->meal_lock, NULL) != 0)
		err_msg("Error creating meal_lock mutex\n");
	if (pthread_mutex_init(&life->death_lock, NULL) != 0)
		err_msg("Error creating death_lock mutex\n");
	if (pthread_mutex_init(&life->msg_lock, NULL) != 0)
		err_msg("Error creating msg_lock mutex\n");
}

void	malloc_life(t_life *life)
{
	life->philos = malloc(sizeof(t_philo) * life->nb_philo);
	if (!life->philos)
	{
		free_life(life);
		err_msg("Malloc error\n");
	}
	life->chopsticks = malloc(sizeof(pthread_mutex_t) * life->nb_philo);
	if (!life->chopsticks)
	{
		free_life(life);
		err_msg("Malloc error\n");
	}
}
