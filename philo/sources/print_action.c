/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:18:29 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/30 19:11:37 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_action(t_philo *philo, char *action, char *color)
{
	struct timeval	current_time;
	long			timecheck;

	pthread_mutex_lock(&philo->mutex->printing);
	pthread_mutex_lock(&philo->mutex->died);
	if (*philo->is_dead == 1 && *action != 'd')
	{
		pthread_mutex_unlock(&philo->mutex->died);
		pthread_mutex_unlock(&philo->mutex->printing);
		return ;
	}
	pthread_mutex_unlock(&philo->mutex->died);
	gettimeofday(&current_time, NULL);
	timecheck = (current_time.tv_sec - philo->day_start.tv_sec) * 1000;
	timecheck += (current_time.tv_usec / 1000
			- philo->day_start.tv_usec / 1000);
	printf("%s%ld %d %s%s\n", color, timecheck,
		philo->philo_nbr, action, RESET);
	pthread_mutex_unlock(&philo->mutex->printing);
}
