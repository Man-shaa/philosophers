/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:20:49 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/08 14:52:24 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Cree les threads puis les join tous a la fois
// Return 0 si tout s'est bien passe, sinon un int positif non nul 
int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input.n_philo)
	{
		if (pthread_create(&data->philo[i].thread, 0, &routine, (void *)data))
			return (1);
		i++;
	}
	i = 0;
	while (i < data->input.n_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			return (2);
		i++;
	}
	return (0);
}
