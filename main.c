/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:24:41 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/27 17:51:17 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

// parsing verifier le nombre de philo (av[1])

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (err_msg(TUTO, 1));
	if (create_data(&data, ac, av))
		return (2);
	print_philo(&data);
	return (0);
}
