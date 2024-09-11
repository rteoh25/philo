/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:48:43 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/11 19:35:43 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_philo	philo;
	t_life	life;

	if (!(ac >= 5 && ac <= 6))
		msg("Bad Arguments\n");
	life = (t_life){0};
	init_life(&life, av, ac);
	return (0);
}
