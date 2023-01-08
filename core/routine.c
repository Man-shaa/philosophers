/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:52:01 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/08 19:02:17 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// int	all_philo_ate(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->input.n_philo)
// 	{
// 		if (data->philo[i].meal_count < data->input.n_meal)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	is_dead(t_data *data, int *i)
{
	(*i)++;
}

int	life_loop(t_data *data, int i)
{
	if (eating(data, i))
		return (1);
	if (sleeping(data, i))
		return (2);
	if (thinking(data, i))
		return (3);
	return (0);
	
}

// Routine de chaque thread philo
void	*routine(void *args)
{
	int		i;
	t_data	*data;

	data = (t_data *)args;
	i = data->thread_i;
	if (data->input.n_meal)
	{
		while (!data->philo_dead && data->philo[i].meal_count < data->input.n_meal)
			life_loop(data, i);
	}
	else
	{
		while (!data->philo_dead)
			if (life_loop(data, i))
				break ;
	}
	return (NULL);
}

void	*check(void *args)
{
	int		i;
	t_data	*data;

	data = (t_data *)args;
	i = 0;
	if (data->input.n_meal)
	{
		while (!data->philo_dead && data->philo[i].meal_count < data->input.n_meal)
			if (is_dead(data, i))
				break ;
	}
	else
	{
		while (!data->philo_dead)
			if (is_dead(data, i))
				break ;
	}
	return (NULL);
}
