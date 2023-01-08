/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:23:16 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/08 14:51:22 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

// actions
# define EATING			"is eating"
# define SLEEPING		"is sleeping"
# define THINKING		"is thinking"
# define TAKEN_FORK		"has taken a fork"
# define PHILO_DIED		"died"

// error
# define MALLOC			"Error caused by a malloc"
# define TUTO			"./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"
# define N_PHILO		"[number_of_philosophers] must be a non null \
positive integer"
# define INT			"All parameters must be a positive integer"
# define THREADS		"Error while creating/joining threads"
# define DATA			"Error while creating t_data structure (malloc problem)"

// colors
# define DEFAULT		"\033[0m"
# define DEAD			"\033[4;31m"
# define RED			"\033[0;31m"
# define GREEN			"\033[0;32m"
# define BLUE			"\033[0;34m"
# define CYAN			"\033[0;36m"

typedef struct s_philo
{
	int			left_fork;
	int			right_fork;
	int			pos;
	int			meal_count;
	pthread_t	thread;
}				t_philo;

typedef struct s_input
{
	long	to_die;
	long	to_eat;
	long	to_sleep;
	int		n_meal;
	int		n_philo;
}				t_input;

typedef struct s_data
{
	int				philo_dead;
	int				thread_index;
	pthread_mutex_t	writing;
	t_input			input;
	t_philo			*philo;
}				t_data;

// *********************************** CORE ***********************************

// actions.c

// routine.c
void	*routine(void *args);

// time.c

// *********************************** CREATE *********************************

// data.c
int		create_data(t_data *data, int ac, char **av);
void	init_input(t_input	*input, int ac, char **av);
void	init_philo(t_data *data, int i, int j);
int		create_philo(t_data *data);

// threads.c
int		create_threads(t_data *data);

// *********************************** FREE ***********************************

// free.c
void	ft_free(void *addr);

// ********************************** PARSING *********************************

// parsing.c
int		is_positive_int(int ac, char **av);
int		parsing(int ac, char **av);

// *********************************** PRINT **********************************

// print.c
int		err_msg(char *s1, int ret_val);
int		print_action(t_data *data, int id, char *action, char *color);

// *********************************** UTILS **********************************

// utils.c
int		ft_strlen(char *str);
void	*ft_calloc(size_t n, size_t size);
long	ft_atoi(const char *str);

#endif