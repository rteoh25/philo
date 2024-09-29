/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:55:28 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/27 18:36:18 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_atos(char *s)
{
	int		i;
	size_t	time;

	i = 0;
	time = 0;
	if (s[i] == '-')
		msg("Input cannot be negative");
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			msg("Invalid char in input");
		if (time > (SIZE_MAX - (s[i] - '0')) / 10)
			msg("Input number exceeds size_t datatype");
		time *= 10;
		time += s[i] - '0';
		i++;
	}
	return (time);
}

void	init_philo(t_life *life)
{
	int	i;
	int	nb_philo;

	nb_philo = life->nb_philo;
	i = -1;
	while (++i < life->nb_philo)
	{
		life->philos[i].idx = i + 1;
		life->philos[i].life = life;
		life->philos[i].meals_eaten = 0;
		life->philos[i].last_meal_t = -1;
		life->philos[i].eating = false;
		life->philos[i].r_chopstick = &life->chopsticks[i];
		life->philos[i].l_chopstick = &life->chopsticks[(i + 1) % nb_philo];
	}
}

void	init_chopstick(t_life *life)
{
	int	i;

	i = -1;
	while (++i < life->nb_philo)
	{
		if (pthread_mutex_init(&life->chopsticks[i], NULL) != 0)
		{
			free_life(life);
			err_msg("Chopstick_error");
		}
	}
}

//to initialize the information and intialize the chopsticks a.k.a the mutexes
//philos are in an array
//mutexes are in an array

void	init_life(t_life *life, char *av[], int ac)
{
	life->start_time = get_time();
	life->end_loop = false;
	life->nb_philo = ft_atoi(av[1]);
	life->time_to_die = ft_atos(av[2]);
	life->time_to_eat = ft_atos(av[3]);
	life->time_to_sleep = ft_atos(av[4]);
	if (ac == 6)
		life->loop_limit = ft_atoi(av[5]);
	if ((ac == 6 && life->loop_limit <= 0) || life->nb_philo <= 0)
		msg("Inputs cannot be zero or negative");
	init_mutex(life);
	malloc_life(life);
}
