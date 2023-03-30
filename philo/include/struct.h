/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:16:29 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/29 17:16:35 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_info
{
	int	number_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_eat;
}	t_info;

typedef struct s_mutex
{
	pthread_mutex_t	printing;
	pthread_mutex_t	died;
}	t_mutex;

typedef struct s_philo
{
	int				philo_nbr;
	int				eat;
	int				*is_dead;
	long			last_meal;
	struct timeval	day_start;
	pthread_mutex_t	fork;
	pthread_mutex_t	last;
	pthread_mutex_t	eat_enough;
	pthread_t		thread;
	struct s_mutex	*mutex;
	struct s_info	*info;
	struct s_philo	*next;
}	t_philo;

#endif
