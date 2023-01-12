/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:06:59 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/12 19:17:21 by msharifi         ###   ########.fr       */
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
	long long	time;
	char		*str;
	char		*id_str;

	if (data->philo_dead)
		return (1);
	time = get_time_from_start(data->t_start);
	if (pthread_mutex_lock(&data->writing))
		return (2);
	if (data->philo_dead)
	{
		if (pthread_mutex_unlock(&data->writing))
			return (3);
		return (1);
	}
	(void)color;
	str = ft_itoa(time);
	str = ft_strjoin(str, "	Philo ");
	id_str = ft_itoa(id);
	str = ft_strjoin(str, id_str);
	ft_free(id_str);
	str = ft_strjoin(str, action);
	str = ft_strjoin(str, "\n");
	write(1, str, ft_strlen(str));
	ft_free(str);
	// printf ("%lld	Philo %d %s%s%s\n", time, id, color, action, DEFAULT);
	if (pthread_mutex_unlock(&data->writing))
		return (3);
	return (0);
}
