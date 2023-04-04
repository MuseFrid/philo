/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:52:30 by gduchesn          #+#    #+#             */
/*   Updated: 2023/04/04 19:08:08 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*lst_last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_last = lstlast(*lst);
	lst_last->next = new;
}
