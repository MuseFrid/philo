/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:18:52 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/25 16:15:34 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = NULL;
	if (argv && (argc == 5 || argc == 6))
	{
		if (check_arg(argc, argv))
			return (gd_error(ARG));
		if (struct_init(argc, argv, &philo))
			return (errno);
		if (init_thread(philo))
			return (errno);
		free_philo(&philo, philo->info, philo->mutex, -1);
		return (0);
	}
	write(2, "Something wrong with arg !\n", 27);
	return (1);
}
