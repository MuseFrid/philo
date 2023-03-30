/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_enum.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:18:41 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/29 17:23:05 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_ENUM_H
# define MY_ENUM_H

enum e_clear_arg
{
	ZERO_MUTEX = 0,
	ONE_MUTEX = 1,
	TWO_MUTEX = 2
};

enum e_error
{
	ARG = 0,
	MALLOC = 1,
	ATOI = 2,
	MUTEX_INIT = 3,
	PHILO_INIT = 4,
	NBR_PHILO = 5,
	PTHREAD = 6,
	UNDER_SIXTY = 7
};

#endif
