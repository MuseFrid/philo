/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_usleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:58:06 by gduchesn          #+#    #+#             */
/*   Updated: 2023/04/04 20:36:45 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	custom_usleep(int time_sleep, int nbr_philo)
{
	struct timeval	current_time;
	int				timecheck;
	int				start_time;

	gettimeofday(&current_time, NULL);
	start_time = ((current_time.tv_sec * STOMS)
			+ (current_time.tv_usec / MITOMS));
	while (1)
	{
		gettimeofday(&current_time, NULL);
		timecheck = ((current_time.tv_sec * STOMS)
				+ (current_time.tv_usec / MITOMS));
		if (timecheck < start_time + time_sleep)
			usleep(nbr_philo * 2);
		else
			break ;
	}
}
