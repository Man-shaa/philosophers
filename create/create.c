/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:24:17 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/27 17:43:36 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_data(t_data *data, int ac, char **av)
{
	init_input(data, ac, av);
	if (create_id(data))
		return (1);
	return (0);
}

int	create_id(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	data->id = ft_calloc(data->input.n_philo, sizeof(t_id));
	if (!data->id)
		return (err_msg(MALLOC, 1));
	while (j < data->input.n_philo)
	{
		init_id(data, i, j);
		i++;
		j++;
	}
	init_id(data, i, 0);
	return (0);
}

void	init_input(t_data *data, int ac, char **av)
{
	data->input.n_philo = ft_atoi(av[1]);
	data->input.to_die = ft_atoi(av[2]);
	data->input.to_eat = ft_atoi(av[3]);
	data->input.to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->input.n_meal = ft_atoi(av[5]);
	else
		data->input.n_meal = 0;
}

void	init_id(t_data *data, int i, int j)
{
	data->id[i].pos = i + 1;
	data->id[i].meal_count = 0;
	data->id[i].left_fork = i;
	data->id[i].right_fork = j;
}