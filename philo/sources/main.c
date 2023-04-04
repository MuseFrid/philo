/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:18:52 by gduchesn          #+#    #+#             */
/*   Updated: 2023/04/04 20:19:40 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = NULL;
	if (argv && (argc == NO_EAT_RESTRICT || argc == EAT_RESTRICT))
	{
		if (check_arg(argc, argv))
			return (gd_error(ARG));
		if (struct_init(argc, argv, &philo))
			return (errno);
		if (init_thread(philo))
			return (errno);
		free_philo(&philo, philo->info, philo->mutex, NO_ERROR_MSG);
		return (SUCCES);
	}
	write(2, "Something wrong with arg !\n", 27);
	return (FAIL);
}
