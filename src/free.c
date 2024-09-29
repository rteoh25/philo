/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:11:39 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/26 11:17:15 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_life(t_life *life)
{
	int	i;

	if (life->philos)
		free(life->philos);
	i = 0;
	while (i < life->nb_philo)
	{
		pthread_mutex_destroy(&life->chopsticks[i]);
		i++;
	}
	free(life->chopsticks);
	pthread_mutex_destroy(&life->death_lock);
	pthread_mutex_destroy(&life->msg_lock);
	pthread_mutex_destroy(&life->meal_lock);
}
