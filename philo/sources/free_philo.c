/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:29:41 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/24 22:30:38 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	free_philo(t_philo **philo, t_info *info, t_mutex *mutex, int pick)
{
	int	how_many;

	if ((*philo)->is_dead)
		free((*philo)->is_dead);
	how_many = info->number_philo;
	free_info_mutex(info, mutex, pick, TWO_MUTEX);
	lstclear(philo, how_many);
	return (1);
}

int	free_info_mutex(t_info *info, t_mutex *mutex, int pick, int level)
{
	if (info)
		free(info);
	if (level >= 1)
		pthread_mutex_destroy(&(mutex->died));
	if (level >= 2)
		pthread_mutex_destroy(&(mutex->printing));
	if (mutex)
		free(mutex);
	if (pick != -1)
		gd_error(pick);
	return (1);
}
