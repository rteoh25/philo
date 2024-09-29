/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:48:43 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/27 15:05:09 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]*/

int	main(int ac, char *av[])
{
	t_life	life;

	if (!(ac >= 5 && ac <= 6))
		msg("Bad Arguments\n");
	life = (t_life){0};
	init_life(&life, av, ac);
	init_chopstick(&life);
	init_philo(&life);
	if ((start_life(&life)) < 0)
	{
		free_life(&life);
		err_msg("Thread_error\n");
	}
	free_life(&life);
	return (0);
}
