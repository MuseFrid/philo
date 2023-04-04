/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:29:41 by gduchesn          #+#    #+#             */
/*   Updated: 2023/04/04 20:05:02 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_philo(t_philo **philo, t_info *info, t_mutex *mutex, int pick)
{
	if (pick != PHILO_INIT && (*philo)->is_dead)
		free((*philo)->is_dead);
	free_info_mutex(info, mutex, pick, TWO_MUTEX);
	lstclear(philo, info->number_philo);
	return (FAIL);
}

int	free_info_mutex(t_info *info, t_mutex *mutex, int pick, int level)
{
	free(info);
	if (level >= ONE_MUTEX)
		pthread_mutex_destroy(&(mutex->died));
	if (level >= TWO_MUTEX)
		pthread_mutex_destroy(&(mutex->printing));
	free(mutex);
	if (pick != NO_ERROR_MSG)
		gd_error(pick);
	return (FAIL);
}
