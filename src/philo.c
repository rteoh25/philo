/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:48:43 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/10 18:57:33 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_philo	philo;
	t_life	life;

	if (!(ac >= 5 && ac <= 6))
		msg("Bad Arguments\n");
	av = NULL;
	philo = (t_philo){0};
	life = (t_life){0};
	initialize_life(&life, av);
	int	i = 0;
	while (i < ac)
	{
		check_if_dead();
		set_eating();
		set_sleeping();
		i = 0;
	}
	return (0);
}
