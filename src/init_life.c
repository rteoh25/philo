/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:55:28 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/11 11:59:31 by rteoh            ###   ########.fr       */
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

static size_t	get_time()
{
	struct	timeval start;
	gettimeofday(&start, NULL);
	return (start.tv_sec * 1000);
}

static void	init_semaphore(t_life *life)
{
	sem_unlink("/chopsticks");
	life->chopsticks = sem_open("/chopsticks", O_CREAT, S_IRWXU, life->num_of_phil);
	if (life->chopsticks <= 0)
		err_msg("sem_open failed");
	else
		printf("semaphore created\n");
}

static void	init_philo(t_life *life)
{
	int	i = 1;
	while (i <= life->num_of_phil)
	{
		life->philos[i].idx = i;
		life->philos[i].life = life;
		i++;
	}
}

void	init_life(t_life *life, char *av[], int ac)
{
	life->start_time = get_time();
	life->num_of_phil = ft_atoi(av[1]);
	if (life->num_of_phil < 2)
		msg("num of philo cannot be less than 2");
	life->time_to_die = ft_atos(av[2]);
	life->time_to_eat = ft_atos(av[3]);
	life->time_to_sleep = ft_atos(av[4]);
	if (ac == 6)
	{
		life->loop_limit = ft_atoi(av[5]);
		if (life->loop_limit <= 0)
			msg("num of loops cannot be negative");
	}
	init_semaphore(life);
	init_philo(life);
}
