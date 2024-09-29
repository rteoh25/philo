/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:31:58 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/27 18:55:09 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include "../libft/libft.h"

# define EAT_TEXT "\033[32mis eating\033[0m"
# define SLEEP_TEXT "\033[34mis sleeping\033[0m"
# define THINK_TEXT "\033[33mis thinking\033[0m"
# define CHOPSTICK_TEXT "\033[37mpicked up a chopstick\033[0m"

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*r_chopstick;
	pthread_mutex_t	*l_chopstick;
	int				idx;
	int				meals_eaten;
	bool			dead;
	bool			eating;
	size_t			last_meal_t;
	struct s_life	*life;
}	t_philo;

typedef struct s_life
{
	int				nb_philo;
	int				loop_limit;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_to_die;
	size_t			start_time;
	t_philo			*philos;
	pthread_mutex_t	*chopsticks;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	msg_lock;
	bool			all_eaten;
	bool			looping;
	bool			end_loop;
}	t_life;

//utils
size_t	get_time(void);
void	sleep_ms(size_t milliseconds);
void	msg(const char *err);
void	err_msg(const char *err);
void	print_msg(char *str, t_philo *philos);

//waiter loop
void	*waiter_routine(void *philo_ptr);

//philo life loop
void	*life_cycle(void *philo_ptr);
int		start_life(t_life *life);

//initialization
void	init_philo(t_life *life);
void	init_chopstick(t_life *life);
void	init_mutex(t_life *life);
void	malloc_life(t_life *life);
void	init_life(t_life *life, char *av[], int ac);

//free
void	free_life(t_life *life);

#endif