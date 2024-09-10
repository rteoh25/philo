/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:55:28 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/10 19:26:20 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_life(t_life *life, char *av[])
{
	life->start_time = get_time();
	life->num_of_phil = ft_atoi(av[1]);
	life->time_to_die = ft_atos(av[2]);
	life->time_to_eat = ft_atos(av[3]);
	life->time_to_sleep = ft_atos(av[4]);
}