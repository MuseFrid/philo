/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:14:09 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/25 16:11:24 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	init_new_mutex(t_philo **new)
{
	if (pthread_mutex_init(&(*new)->fork, NULL))
		return (1);
	if (pthread_mutex_init(&(*new)->last, NULL))
	{
		pthread_mutex_destroy(&(*new)->fork);
		return (1);
	}
	if (pthread_mutex_init(&(*new)->eat_enough, NULL))
	{
		pthread_mutex_destroy(&(*new)->fork);
		pthread_mutex_destroy(&(*new)->last);
		return (1);
	}
	return (0);
}

t_philo	*lstnew(int nbr, t_info *info, t_mutex *mutex, int *is_dead)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->philo_nbr = nbr;
	new->eat = 0;
	new->last_meal = 0;
	new->is_dead = is_dead;
	new->mutex = mutex;
	new->info = info;
	new->next = NULL;
	new->day_start.tv_sec = 0;
	new->day_start.tv_usec = 0;
	if (init_new_mutex(&new))
	{
		free(new);
		return (NULL);
	}
	return (new);
}
