/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:32:46 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/08 17:29:27 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Verifie que tous les arguments recus sont positifs et dans la range d'un int
// Return 0 si tous sont conformes, sinon 1
int	is_positive_int(int ac, char **av)
{
	int		i;
	long	res;

	i = 1;
	while (i < ac)
	{
		res = ft_atoi(av[i]);
		if (res < 0 || res > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

// Verifie que les arguments recus sont conformes
// return 0 si tout est bon, sinon un int positif non nul
int	parsing(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (err_msg(TUTO, 1));
	if (ft_atoi(av[1]) <= 0)
		return (err_msg(N_PHILO, 2));
	if (is_positive_int(ac, av))
		return (err_msg(INT, 3));
	return (0);
}
