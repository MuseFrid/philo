/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_usleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:58:06 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/24 23:39:03 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	custom_usleep(int time_sleep)
{
	struct timeval	current_time;
	int				timecheck;
	int				start_time;

	gettimeofday(&current_time, NULL);
	start_time = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	while (1)
	{
		gettimeofday(&current_time, NULL);
		timecheck = ((current_time.tv_sec * 1000)
				+ (current_time.tv_usec / 1000));
		if (timecheck < start_time + time_sleep)
			usleep(100);
		else
			break ;
	}
}
