/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:32:46 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/27 18:50:19 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parsing(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (err_msg(TUTO, 1));
	if (ft_atoi(av[1]) <= 0)
		return (err_msg(N_PHILO, 2));
	return (0);
}
