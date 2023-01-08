/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:06:59 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/08 14:31:58 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	err_msg(char *s1, int ret_val)
{
	if (s1)
		write(STDERR_FILENO, s1, ft_strlen(s1));
	write(STDERR_FILENO, "\n", 1);
	return (ret_val);
}

int	print_action(t_data *data, int id, char *action, char *color)
{
	if (pthread_mutex_lock(&data->writing))
		return (1);
	printf ("Philo %d %s%s%s\n", id, color, action, DEFAULT);
	if (pthread_mutex_unlock(&data->writing))
		return (2);
	return (0);
}
