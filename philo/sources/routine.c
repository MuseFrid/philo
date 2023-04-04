/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:19:16 by gduchesn          #+#    #+#             */
/*   Updated: 2023/04/04 20:37:11 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	one_philo_waiting_dead(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->mutex->died);
		if (*philo->is_dead == YES)
			break ;
		pthread_mutex_unlock(&philo->mutex->died);
	}
	pthread_mutex_unlock(&philo->mutex->died);
}

static void	eating(t_philo *philo)
{
	struct timeval	current_time;
	long			timecheck;

	pthread_mutex_lock(&philo->fork);
	print_action(philo, "has taken a fork", BOLDMAGENTA);
	if (philo->next)
	{
		pthread_mutex_lock(&philo->next->fork);
		print_action(philo, "has taken a fork", BOLDMAGENTA);
		gettimeofday(&current_time, NULL);
		timecheck = (current_time.tv_sec * STOMS
				+ current_time.tv_usec / MITOMS);
		pthread_mutex_lock(&philo->last);
		philo->last_meal = timecheck;
		pthread_mutex_unlock(&philo->last);
		print_action(philo, "is eating", BOLDGREEN);
		pthread_mutex_lock(&philo->eat_enough);
		philo->eat++;
		pthread_mutex_unlock(&philo->eat_enough);
		custom_usleep(philo->info->time_to_eat, philo->info->number_philo);
		pthread_mutex_unlock(&philo->next->fork);
	}
	else
		one_philo_waiting_dead(philo);
	pthread_mutex_unlock(&philo->fork);
}

void	*philo_routine(void *info)
{
	t_philo	*philo;

	philo = (t_philo *) info;
	if (philo->philo_nbr % 2 == EVEN)
		custom_usleep(philo->info->time_to_eat / 2, philo->info->number_philo);
	while (1)
	{
		pthread_mutex_lock(&philo->mutex->died);
		if (*philo->is_dead == YES)
			break ;
		pthread_mutex_unlock(&philo->mutex->died);
		eating(philo);
		print_action(philo, "is sleeping", BOLDYELLOW);
		custom_usleep(philo->info->time_to_sleep, philo->info->number_philo);
		print_action(philo, "is thinking", BOLDCYAN);
	}
	pthread_mutex_unlock(&philo->mutex->died);
	return (info);
}
