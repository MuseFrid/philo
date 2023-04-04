/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_macro.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:29:33 by gduchesn          #+#    #+#             */
/*   Updated: 2023/04/04 20:35:29 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_MACRO_H
# define ENUM_MACRO_H

# define NO_ERROR_MSG -1
# define SUCCES 0
# define FAIL 1
# define NO_NBR_EAT -1
# define IS_NBR_EAT 6
# define NO_EAT_RESTRICT 5
# define EAT_RESTRICT 6
# define NO 0
# define YES 1
# define ONLY_ONE 1
# define NO_PHILO 0
# define NOT_EAT_YET 0
# define THEY_ALL_EAT_ENOUGH 0
# define MITOMS 1000
# define STOMS 1000
# define WRONG_ARG 60
# define END_LST 1
# define EVEN 0
# define DEAD 1
# define NO_FREE NULL

enum e_atoi
{
	NBR_PHILO = 1,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	NBR_EAT
};
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
	WRONG_NBR_PHILO = 5,
	PTHREAD = 6,
	UNDER_SIXTY = 7
};

#endif
