/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:52:46 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/25 15:54:00 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	lstclear(t_philo **lst, int how_many)
{
	t_philo	*buf_lst;
	int		i;

	i = 0;
	if (!*lst)
		return ;
	while (i++ < how_many)
	{
		buf_lst = *lst;
		if ((*lst)->next)
			*lst = (*lst)->next;
		pthread_mutex_destroy(&(*lst)->fork);
		pthread_mutex_destroy(&(*lst)->last);
		pthread_mutex_destroy(&(*lst)->eat_enough);
		free(buf_lst);
		buf_lst = NULL;
	}
	lst = NULL;
}
