/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:50:49 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/29 05:26:35 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	meal_check(t_life *life)
{
	int		i;
	int		count;
	t_philo	*philos;

	philos = life->philos;
	if (life->loop_limit == 0)
		return (0);
	i = -1;
	count = 0;
	while (++i < life->nb_philo)
	{
		pthread_mutex_lock(&life->meal_lock);
		if (philos[i].meals_eaten >= life->loop_limit)
			count++;
		pthread_mutex_unlock(&life->meal_lock);
	}
	if (count == life->nb_philo)
	{
		pthread_mutex_lock(&life->death_lock);
		life->end_loop = true;
		pthread_mutex_unlock(&life->death_lock);
		return (1);
	}
	return (0);
}

static void	philo_dieded(t_life *life)
{
	t_philo	*philos;

	philos = life->philos;
	print_msg("\033[1;31mhas died\033[0m", philos);
	pthread_mutex_lock(&life->death_lock);
	life->end_loop = true;
	pthread_mutex_unlock(&life->death_lock);
	pthread_mutex_unlock(&life->meal_lock);
}

static int	death_check(t_life *life)
{
	t_philo		*philos;
	int			i;

	philos = life->philos;
	if (get_time() < (life->start_time + life->time_to_die))
		return (0);
	i = -1;
	while (++i < life->nb_philo)
	{
		pthread_mutex_lock(&life->meal_lock);
		if ((get_time() - philos[i].last_meal_t >= life->time_to_die)
			&& (philos[i].eating == false))
		{
			philo_dieded(life);
			return (1);
		}
		pthread_mutex_unlock(&life->meal_lock);
	}
	// usleep(10);
	return (0);
}

void	*waiter_routine(void *life_ptr)
{
	t_life	*life;

	life = (t_life *)life_ptr;
	while (1)
	{
		if (meal_check(life) || death_check(life))
			break ;
	}
	return (life_ptr);
}
