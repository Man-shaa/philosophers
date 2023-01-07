/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:16 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/27 18:22:49 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_free(void *addr)
{
	free(addr);
	addr = NULL;
}

void	free_philo(t_data data)
{
	if (data.philo)
		ft_free(data.philo);
}
