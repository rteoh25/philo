/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:31:38 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/29 05:08:34 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(const char *err)
{
	printf("Error:\n");
	printf("      %s\n", err);
	exit (EXIT_SUCCESS);
}

void	err_msg(const char *err)
{
	perror(err);
	exit (EXIT_FAILURE);
}

size_t	get_time(void)
{
	struct timeval	start;

	if (gettimeofday(&start, NULL))
		return (0);
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000));
}

void	print_msg(char *str, t_philo *philos)
{
	size_t	time;
	t_life	*life;

	life = philos->life;
	time = get_time() - life->start_time;
	pthread_mutex_lock(&life->death_lock);
	pthread_mutex_lock(&life->msg_lock);
	if (life->end_loop == false)
		printf("%zu %i %s\n", time, philos->idx, str);
	pthread_mutex_unlock(&life->msg_lock);
	pthread_mutex_unlock(&life->death_lock);
}

void	sleep_ms(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
}
