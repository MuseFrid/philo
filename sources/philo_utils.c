/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:55:15 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/22 17:51:47 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long long	i;
	long long	num;
	int			sign;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			sign *= -1;
	while (str[i] && ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - 48);
		i++;
		if (sign == -1 && (-num) > 2147483648 && ++errno)
			return (0);
		if (sign == 1 && (-num) > 2147483647 && ++errno)
			return (-1);
	}
	if (sign == -1)
		return (-num);
	return (num);
}
