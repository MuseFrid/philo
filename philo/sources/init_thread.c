/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:47:08 by gduchesn          #+#    #+#             */
/*   Updated: 2023/04/04 20:16:54 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	end_everything(t_philo *philo, pthread_t *living)
{
	t_philo	*snake;

	snake = philo;
	pthread_mutex_lock(&philo->mutex->died);
	*philo->is_dead = DEAD;
	pthread_mutex_unlock(&philo->mutex->died);
	while (1)
	{
		pthread_join(snake->thread, NULL);
		snake = snake->next;
		if (snake->philo_nbr == END_LST)
			break ;
	}
	pthread_join(*living, NULL);
	pthread_mutex_lock(&philo->mutex->printing);
	free_philo(&philo, philo->info, philo->mutex, PTHREAD);
	return (FAIL);
}

static int	wait_the_end(t_philo *philo, t_philo *snake, pthread_t *living)
{
	while (1)
	{
		if (pthread_join(snake->thread, NULL))
			return (end_everything(philo, living));
		if (snake->next)
			snake = snake->next;
		if (snake->philo_nbr == END_LST)
			break ;
	}
	if (pthread_join(*living, NULL))
		return (end_everything(philo, living));
	return (SUCCES);
}

int	init_thread(t_philo *philo)
{
	t_philo		*snake;
	pthread_t	living;

	snake = philo;
	if (pthread_create(&living, NULL, &are_they_living, philo))
		return (end_everything(philo, &living));
	while (1)
	{
		if (pthread_create(&(snake->thread), NULL, &philo_routine, snake))
			return (end_everything(philo, &living));
		if (snake->next)
			snake = snake->next;
		if (snake->philo_nbr == END_LST)
			break ;
	}
	return (wait_the_end(philo, snake, &living));
}
