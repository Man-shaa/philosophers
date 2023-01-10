/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:16 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/10 15:48:26 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_free(void *addr)
{
	free(addr);
	addr = NULL;
}

void	free_data(t_data data)
{
	if (data.fork)
		ft_free(data.fork);
	if (data.philo)
		ft_free(data.philo);
}
