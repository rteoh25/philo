/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:02:18 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/28 22:49:41 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_life(t_life *life)
{
	t_philo		*philos;
	pthread_t	waiter;
	int			i;

	i = -1;
	philos = life->philos;
	if (pthread_create(&waiter, NULL, &waiter_routine, (void *)life) != 0)
		return (-1);
	while (++i < life->nb_philo)
	{
		if (pthread_create(&(philos[i].thread),
				NULL, &life_cycle, (void *)&philos[i]) != 0)
			return (-1);
	}
	if (pthread_join(waiter, NULL) != 0)
		return (-1);
	i = -1;
	while (++i < life->nb_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (-1);
	}
	return (0);
}
