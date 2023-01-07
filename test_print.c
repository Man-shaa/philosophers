/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:46:53 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/27 18:22:01 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	print_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = data->philo;
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
		printf("\n");
	}
}

void	print_input(t_input input)
{
	printf ("\n************************* INPUT *************************\n\n");
	printf("   n_philo : [%d]\n", input.n_philo);
	printf("   to_die : [%ld]\n", input.to_die);
	printf("   to_eat : [%ld]\n", input.to_eat);
	printf("   to_sleep : [%ld]\n", input.to_sleep);
	printf("   n_meal : [%d]\n\n", input.n_meal);
}
