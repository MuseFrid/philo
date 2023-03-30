/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:36:43 by gduchesn          #+#    #+#             */
/*   Updated: 2023/03/30 18:25:15 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/errno.h>
# include <stdlib.h>
# include "color.h"
# include "struct.h"
# include "my_enum.h"

# define NO_FREE NULL
# define DEAD 1

int		check_arg(int argc, char **argv);
int		info_check(t_info *info);
int		gd_error(int pick);

void	lstadd_back(t_philo **lst, t_philo *new);
void	lstclear(t_philo **lst, int how_many);
t_philo	*lstlast(t_philo *lst);
t_philo	*lstnew(int nbr, t_info *info, t_mutex *mutex, int *is_dead);

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	custom_usleep(int time_sleep, int nbr_philo);

int		free_philo(t_philo **philo, t_info *info, t_mutex *mutex, int pick);
int		free_info_mutex(t_info *info, t_mutex *mutex, int pick, int level);

int		struct_init(int argc, char **argv, t_philo **head);
int		init_thread(t_philo *philo);
void	print_action(t_philo *philo, char *action, char *color);
void	*philo_routine(void *info);
void	*are_they_living(void *info);

#endif
