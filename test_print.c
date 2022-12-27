/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:46:53 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/27 17:49:12 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	print_philo(t_data *data)
{
	int		i;
	t_id	*philo;

	philo = data->id;
	i = 0;
	printf("\n");
	while (i < data->input.n_philo)
	{
		printf("********** Philo number [%d] **********\n\n", philo[i].pos);
		printf("  Pos : [%d]\n", philo[i].pos);
		printf("  Left fork : [%d]\n", philo[i].left_fork);
		printf("  Right fork : [%d]\n", philo[i].right_fork);
		printf("  Meal count : [%d]\n", philo[i].meal_count);
		// printf("  Time to die : [%lld]\n\n", philo[i].time_to_die);
		i++;
	}
}
