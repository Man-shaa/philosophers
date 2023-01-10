/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:20:49 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/10 15:30:10 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Cree les threads de chaque philo + checker
// Return 0 si tout s'est bien passe, sinon un int positif non nul 
int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->writing, NULL))
		return (err_msg(MUTEX, 1));
	data->t_start = get_time();
	while (i < data->input.n_philo)
	{
		data->thread_i = i;
		if (pthread_create(&data->philo[i].thread, 0, &routine, (void *)data))
			return (err_msg(THREADS, 2));
		usleep(1000);
		i++;
	}
	if (pthread_create(&data->checker, 0, &check, (void *)data))
		return (err_msg(THREADS, 2));
	usleep(1000);
	return (join_threads(data));
}

// Join les threads de chaque philo + checker
// Return 0 si tout s'est bien passe, sinon 3
int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input.n_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			return (err_msg(THREADS, 3));
		usleep(1000);
		i++;
	}
	if (pthread_join(data->checker, NULL))
		return (err_msg(THREADS, 3));
	usleep(1000);
	return (0);
}
