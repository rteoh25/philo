/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:48:43 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/11 00:47:22 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_philo	philo;
	t_life	life;

	if (!(ac >= 5 && ac <= 6))
		msg("Bad Arguments\n");
	philo = (t_philo){0};
	life = (t_life){0};
	init_life(&life, av, ac);
	// int	i = 0;
	// while (i < ac)
	// {
	// 	check_if_dead();
	// 	set_eating();
	// 	set_sleeping();
	// 	i = 0;
	// }
	return (0);
}
