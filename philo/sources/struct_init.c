/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:05:27 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/29 17:26:23 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	info_init(int argc, char **argv, t_info **info)
{
	*info = (t_info *)malloc(sizeof(t_info));
	if (!*info)
		return (free_info_mutex(NO_FREE, NO_FREE, MALLOC, ZERO_MUTEX));
	(*info)->number_philo = ft_atoi(argv[1]);
	(*info)->time_to_die = ft_atoi(argv[2]);
	(*info)->time_to_eat = ft_atoi(argv[3]);
	(*info)->time_to_sleep = ft_atoi(argv[4]);
	(*info)->nbr_eat = -1;
	if (argc == 6)
		(*info)->nbr_eat = ft_atoi(argv[5]);
	if (errno)
		return (free_info_mutex(*info, NO_FREE, ATOI, ZERO_MUTEX));
	if (info_check(*info))
		return (free_info_mutex(*info, NO_FREE, errno, ZERO_MUTEX));
	return (errno);
}

static int	mutex_init(t_info *info, t_mutex **mutex)
{
	*mutex = (t_mutex *)malloc(sizeof(t_mutex));
	if (!mutex)
		return (free_info_mutex(info, NO_FREE, MALLOC, ZERO_MUTEX));
	if (pthread_mutex_init(&(*mutex)->died, NULL))
		return (free_info_mutex(info, *mutex, MUTEX_INIT, ZERO_MUTEX));
	if (pthread_mutex_init(&(*mutex)->printing, NULL))
		return (free_info_mutex(info, *mutex, MUTEX_INIT, ONE_MUTEX));
	return (errno);
}

static int	init_is_dead(int **is_dead)
{
	*is_dead = (int *)malloc(sizeof(int));
	if (!*is_dead)
		return (1);
	**is_dead = 0;
	return (0);
}

static int	philo_init(t_philo **head, t_info *info, t_mutex *mutex)
{
	int				*is_dead;
	int				i;
	t_philo			*new;
	struct timeval	day_start;

	i = 0;
	gettimeofday(&day_start, NULL);
	if (init_is_dead(&is_dead))
		return (free_info_mutex(info, mutex, MALLOC, TWO_MUTEX));
	while (i++ < info->number_philo)
	{
		new = lstnew(i, info, mutex, is_dead);
		if (!new)
		{
			free(is_dead);
			return (free_philo(head, info, mutex, PHILO_INIT));
		}
		new->day_start.tv_sec = day_start.tv_sec;
		new->day_start.tv_usec = day_start.tv_usec;
		lstadd_back(head, new);
	}
	if (info->number_philo != 1)
		new->next = *head;
	return (0);
}

int	struct_init(int argc, char **argv, t_philo **head)
{
	t_info	*info;
	t_mutex	*mutex;

	info = NULL;
	mutex = NULL;
	if (info_init(argc, argv, &info))
		return (1);
	if (mutex_init(info, &mutex))
		return (1);
	if (philo_init(head, info, mutex))
		return (1);
	return (0);
}
