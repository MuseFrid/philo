/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:24:25 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/29 17:25:59 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	info_check(t_info *info)
{
	if (info->number_philo == 0)
	{
		errno = NBR_PHILO;
		return (1);
	}
	if (info->time_to_die < 60 || info->time_to_eat < 60
		|| info->time_to_sleep < 60)
	{
		errno = UNDER_SIXTY;
		return (1);
	}
	return (0);
}
