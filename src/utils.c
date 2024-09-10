/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:31:38 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/10 17:52:37 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(const char *err)
{
	printf("Error:\n");
	printf("%s\n", err);
	exit (EXIT_SUCCESS);
}

void	err_msg(const char *err)
{
	perror(err);
	exit (EXIT_FAILURE);
}