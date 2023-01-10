/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:52:01 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/10 17:47:26 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Check si data->philo[i] est mort
int	is_dead(t_data *data, int *i)
{
	long long	time;

	if ((*i) == data->input.n_philo)
		(*i) = 0;
	time = get_time_from_start(data->philo[(*i)].t_until_die);
	if (time > data->input.to_die)
	{
		print_action(data, *i + 1, PHILO_DIED, DEAD);
		data->philo_dead = 1;
		return (1);
	}
	ft_usleep(1);
	(*i)++;
	return (0);
}

// Toutes les actions que chaque philo fait dans l'ordre
int	life_loop(t_data *data, int i)
{
	if (data->philo_dead == 1)
		return (1);
	if (eating(data, i))
		return (2);
	if (data->philo_dead == 1)
		return (1);
	if (sleeping(data, i))
		return (3);
	if (data->philo_dead == 1)
		return (1);
	if (thinking(data, i))
		return (4);
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
		while (!data->philo_dead
			&& data->philo[i].meal_count < data->input.n_meal)
			if (life_loop(data, i))
				return (NULL);
	}
	else
	{
		while (!data->philo_dead)
			if (life_loop(data, i))
				return (NULL);
	}
	return (NULL);
}

// Checker philo mort
void	*check(void *args)
{
	int		i;
	t_data	*data;

	data = (t_data *)args;
	i = 0;
	if (data->input.n_meal)
	{
		while (!data->philo_dead
			&& data->philo[i].meal_count < data->input.n_meal)
			if (is_dead(data, &i))
				return (NULL);
	}
	else
	{
		while (!data->philo_dead)
			if (is_dead(data, &i))
				return (NULL);
	}
	return (NULL);
}
