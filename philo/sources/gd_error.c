/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:53:10 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/29 17:20:59 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	gd_error(int pick)
{
	static char	*error[] = {
		"Error\nAt least one arg is not properly formated !\n \
			\rNegative number ? Not a digit ? 0 philo ?\n", \
		"Error\nMalloc failed\n", \
		"Error\nAtoi failed\n", \
		"Error\nAt least one mutex_init failed\n", \
		"Error\nPhilo_init failed\n", \
		"Error\nNeed at least one philo !\n", \
		"Error\npthread failed to create a thread\n", \
		"Error\nAt least one arg (not philo) is under sixty !\n"};

	write(2, RED, ft_strlen(RED));
	if (pick > 7)
		write(2, "Error\n", 6);
	else
		write(2, error[pick], ft_strlen(error[pick]));
	write(2, RESET, ft_strlen(RESET));
	errno = pick + 1;
	return (pick + 1);
}
