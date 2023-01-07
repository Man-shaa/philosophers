/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:20:49 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/07 21:32:53 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	while (data->test <= 30)
	{
		data->test += 5;
		printf("Apres incrementation : %d\n", data->test);
	}
	return (NULL);	
}

void	*end_check(void *args)
{
	t_data *data;

	data = (t_data *)args;
	if (data->test >= 10)
		printf("Seuil de 10 atteint\n");
	printf("%i\n", data->test);
	return (NULL);
}

int	create_threads(t_data *data)
{
	int	i;
	pthread_t	end;

	data->test = 0;
	i = 0;
	pthread_create(&end, NULL, &end_check, (void *)data);
	while (i < data->input.n_philo)
	{
		if (pthread_create(&data->philo[i].thread, 0, &routine, (void *)data))
			return (1);
		i++;
	}
	if (pthread_join(end, NULL))
		return (2);
	i = 0;
	while (i < data->input.n_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			return (2);
		i++;
	}
	return (0);
}
