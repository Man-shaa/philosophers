/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:13:09 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/08 17:36:00 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Cree les mutex sur les forks
// Return 0 si la creation a fonctionnee, sinon un int positif non nul
int	create_fork(t_data *data)
{
	int	i;

	i = 0;
	data->fork = ft_calloc(data->input.n_philo, sizeof(pthread_mutex_t));
	if (!data->fork)
		return (err_msg(MALLOC, 1));
	while (i < data->input.n_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (ft_free(data->fork), err_msg(MUTEX, 2));
		i++;
	}
	return (0);
}
