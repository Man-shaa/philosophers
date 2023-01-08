/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:24:41 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/08 14:50:34 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

// Si 1 seul philo !

void	print_philo(t_data data);
void	print_input(t_input input);

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing(ac, av))
		return (1);
	if (create_data(&data, ac, av))
		return (err_msg(DATA, 2));
	if (create_threads(&data))
		return (ft_free(data.philo), err_msg(THREADS, 3));
	print_input(data.input);
	print_philo(data);
	if (data.philo)
		ft_free(data.philo);
	return (0);
}
