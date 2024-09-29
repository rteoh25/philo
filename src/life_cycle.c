/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:06:42 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/29 05:05:38 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_philo *philo)
{
	t_life	*life;

	life = philo->life;
	if (life->nb_philo < 2)
	{
		sleep_ms(life->time_to_die);
		return ;
	}
	pthread_mutex_lock(philo->l_chopstick);
	print_msg(CHOPSTICK_TEXT, philo);
	pthread_mutex_lock(philo->r_chopstick);
	print_msg(CHOPSTICK_TEXT, philo);
	print_msg(EAT_TEXT, philo);
	pthread_mutex_lock(&life->meal_lock);
	philo->last_meal_t = get_time();
	philo->eating = true;
	philo->meals_eaten++;
	pthread_mutex_unlock(&life->meal_lock);
	sleep_ms(philo->life->time_to_eat);
	philo->eating = false;
	pthread_mutex_unlock(philo->r_chopstick);
	pthread_mutex_unlock(philo->l_chopstick);
}

static void	philo_sleep(t_philo *philo)
{
	print_msg(SLEEP_TEXT, philo);
	sleep_ms(philo->life->time_to_sleep);
}

static void	philo_think(t_philo *philo)
{
	print_msg(THINK_TEXT, philo);
}

static int	check_loop(t_life *life)
{
	pthread_mutex_lock(&life->death_lock);
	if (life->end_loop == true)
	{
		pthread_mutex_unlock(&life->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&life->death_lock);
	return (0);
}

void	*life_cycle(void *philo_ptr)
{
	t_philo		*philo;
	t_life		*life;

	philo = (t_philo *)philo_ptr;
	life = philo->life;
	if ((philo->idx % 2) == 0)
		sleep_ms(life->time_to_eat - 10);
	while (check_loop(life) == 0)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (philo_ptr);
}
