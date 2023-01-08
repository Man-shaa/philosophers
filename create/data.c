/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:24:17 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/08 14:52:06 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Cree et remplit la structure t_data
// Return 0 si la creation a fonctionnee, sinon 1 (probleme malloc)
int	create_data(t_data *data, int ac, char **av)
{
	data->philo_dead = 0;
	init_input(&data->input, ac, av);
	if (create_philo(data))
		return (1);
	return (0);
}

// Cree les philos et les initialise avec init_philo()
// Return 0 si la creation s'est bien passee, sinon 1 (probleme malloc)
int	create_philo(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	data->philo = ft_calloc(data->input.n_philo, sizeof(t_philo));
	if (!data->philo)
		return (err_msg(MALLOC, 1));
	while (j < data->input.n_philo)
	{
		init_philo(data, i, j);
		i++;
		j++;
	}
	init_philo(data, i, 0);
	return (0);
}

// Initialise la structure t_input avec les arguments recus
void	init_input(t_input *input, int ac, char **av)
{
	input->n_philo = ft_atoi(av[1]);
	input->to_die = ft_atoi(av[2]);
	input->to_eat = ft_atoi(av[3]);
	input->to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		input->n_meal = ft_atoi(av[5]);
	else
		input->n_meal = 0;
}

// Initialise chaque philo de la structure t_philo
void	init_philo(t_data *data, int i, int j)
{
	data->philo[i].pos = i + 1;
	data->philo[i].meal_count = 0;
	data->philo[i].left_fork = i;
	data->philo[i].right_fork = j;
}
