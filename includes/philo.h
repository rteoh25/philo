/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:31:58 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/11 15:07:48 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include "../libft/libft.h"

typedef struct	s_philo
{
	pthread_t		thread;
	int				idx;
	int				r_chopstick_idx;
	int				l_chopstick_idx;
	bool			dead;
	bool			eating;
	bool			sleeping;
	size_t			last_meal_t;
	struct	s_life	*life;
}	t_philo;

typedef struct s_life
{
	int				num_of_phil;
	int				loop_limit;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_to_die;
	size_t			start_time;
	t_philo			philos[250];
	pthread_mutex_t	chopsticks[250];
	bool	end_loop;
}	t_life;


void	init_life(t_life *life, char *av[], int ac);
void	msg(const char *err);
void	err_msg(const char *err);



#endif