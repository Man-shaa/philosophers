/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:24:41 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/12 21:58:29 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"


// int	one_philo(t_data *data)
// {
	
// 	return (0);
// }

void	print_philo(t_data data);
void	print_input(t_input input);

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing(ac, av))
		return (1);
	if (create_data(&data, ac, av))
		return (2);
	if (create_threads(&data))
		return (free_data(data), 3);
	free_data(data);
	return (0);
}
