/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:31:58 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/10 19:24:08 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_life
{
	int		num_of_phil;
	int		loop_limit;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	time_to_die;
	size_t	last_meal;
	size_t	start_time;
	bool	end_loop;
}	t_life;


typedef struct	s_philo
{
	pthread_t	thread;
	bool	dead;
	bool	eating;
	bool	sleeping;

	pthread_mutex_t r_chopstick;
	pthread_mutex_t	l_chopstick;
	struct s_philo	*next;

}	t_philo;

void	msg(const char *err);
void	err_msg(const char *err);



#endif