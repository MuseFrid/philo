/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:24:25 by gduchesn          #+#    #+#             */
/*   Updated: 2023/04/04 20:36:12 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	info_check(t_info *info)
{
	if (info->number_philo == NO_PHILO)
	{
		errno = WRONG_NBR_PHILO;
		return (FAIL);
	}
	if (info->time_to_die < WRONG_ARG || info->time_to_eat < WRONG_ARG
		|| info->time_to_sleep < WRONG_ARG)
	{
		errno = UNDER_SIXTY;
		return (FAIL);
	}
	return (SUCCES);
}
