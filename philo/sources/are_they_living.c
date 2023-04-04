/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_they_living.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:51:59 by gduchesn          #+#    #+#             */
/*   Updated: 2023/04/04 20:10:57 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	something_crash(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->died);
	if (*philo->is_dead == DEAD)
	{
		pthread_mutex_unlock(&philo->mutex->died);
		return (FAIL);
	}
	pthread_mutex_unlock(&philo->mutex->died);
	return (SUCCES);
}

static int	is_he_dead(t_philo *philo, long start_time)
{
	struct timeval	current_time;
	long			timecheck;

	gettimeofday(&current_time, NULL);
	timecheck = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
	pthread_mutex_lock(&philo->last);
	if (philo->last_meal == NOT_EAT_YET)
		philo->last_meal = start_time;
	if ((timecheck - philo->last_meal)
		> philo->info->time_to_die)
	{
		pthread_mutex_lock(&philo->mutex->died);
		*philo->is_dead = DEAD;
		pthread_mutex_unlock(&philo->mutex->died);
		pthread_mutex_unlock(&philo->last);
		return (FAIL);
	}
	pthread_mutex_unlock(&philo->last);
	return (SUCCES);
}

static int	have_they_eat_enough(t_philo *philo)
{
	int	stop;
	int	they_have_eat_enough;

	stop = philo->philo_nbr;
	they_have_eat_enough = 1;
	if (philo->info->nbr_eat == NO_NBR_EAT)
		return (SUCCES);
	while (1)
	{
		pthread_mutex_lock(&philo->eat_enough);
		if (!(philo->eat >= philo->info->nbr_eat))
			they_have_eat_enough = THEY_ALL_EAT_ENOUGH;
		pthread_mutex_unlock(&philo->eat_enough);
		if (philo->next)
			philo = philo->next;
		if (philo->philo_nbr == stop)
			break ;
	}
	if (they_have_eat_enough == THEY_ALL_EAT_ENOUGH)
		return (SUCCES);
	pthread_mutex_lock(&philo->mutex->died);
	*philo->is_dead = DEAD;
	pthread_mutex_unlock(&philo->mutex->died);
	return (FAIL);
}

void	*are_they_living(void *info)
{
	t_philo			*philo;
	long			start;

	philo = (t_philo *) info;
	start = (philo->day_start.tv_sec * 1000 + philo->day_start.tv_usec / 1000);
	while (1)
	{
		if (something_crash(philo))
			return (NULL);
		if (is_he_dead(philo, start))
			break ;
		if (have_they_eat_enough(philo))
			return (NULL);
		if (philo->next)
			philo = philo->next;
	}
	pthread_mutex_lock(&philo->mutex->died);
	if (*philo->is_dead == YES)
	{
		pthread_mutex_unlock(&philo->mutex->died);
		print_action(philo, "died", BOLDRED);
	}
	else
		pthread_mutex_unlock(&philo->mutex->died);
	return (NULL);
}
