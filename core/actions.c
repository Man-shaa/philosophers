/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:55:38 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/08 18:58:21 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eating(t_data *data, int i)
{
	if (pthread_mutex_lock(&data->fork[data->philo[i].left_fork]))
		return (1);
	if (print_action(data, data->philo[i].pos, TAKEN_FORK, GREEN))
		return (2);
	if (pthread_mutex_lock(&data->fork[data->philo[i].right_fork]))
		return (3);
	if (print_action(data, data->philo[i].pos, TAKEN_FORK, GREEN))
		return (4);
	if (print_action(data, data->philo[i].pos, EATING, BLUE))
		return (5);
	data->philo[i].t_until_die = get_time();
	action_time(data->input.to_eat);
	if (pthread_mutex_unlock(&data->fork[data->philo[i].left_fork]))
		return (6);
	if (pthread_mutex_unlock(&data->fork[data->philo[i].right_fork]))
		return (7);
	data->philo[i].meal_count++;
	return (0);
}

int	sleeping(t_data *data, int i)
{
	if (print_action(data, data->philo[i].pos, SLEEPING, CYAN))
		return (1);
	action_time(data->input.to_sleep);
	return (0);
}

int	thinking(t_data *data, int i)
{
	if (print_action(data, data->philo[i].pos, THINKING, DEFAULT))
		return (1);
	return (0);
}
