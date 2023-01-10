/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:23:16 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/10 15:48:41 by msharifi         ###   ########.fr       */
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
# define MUTEX			"Error caused by a mutex init"
# define TUTO			"./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"
# define N_PHILO		"[number_of_philosophers] must be a non null \
positive integer"
# define INT			"All parameters must be a positive integer"
# define THREADS		"Error while creating/joining threads"
# define PHILO			"Error while creating t_philo structure (malloc)"

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
	long long	t_until_die;
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
	long long		t_start;
	int				thread_i;
	pthread_t		checker;
	pthread_mutex_t	writing;
	pthread_mutex_t	*fork;
	t_input			input;
	t_philo			*philo;
}				t_data;

// *********************************** CORE ***********************************

// actions.c
int			eating(t_data *data, int i);
int			sleeping(t_data *data, int i);
int			thinking(t_data *data, int i);

// routine.c
int			life_loop(t_data *data, int i);
void		*routine(void *args);
void		*check(void *args);

// time.c
long long	get_time(void);
long long	get_time_from_start(long long time);
void		ft_usleep(long int time_in_ms);
void		action_time(size_t time);

// *********************************** CREATE *********************************

// data.c
int			create_data(t_data *data, int ac, char **av);
void		init_input(t_input	*input, int ac, char **av);
void		init_philo(t_data *data, int i, int j);
int			create_philo(t_data *data);

// fork.c
int			create_fork(t_data *data);

// threads.c
int			create_threads(t_data *data);
int			join_threads(t_data *data);

// *********************************** FREE ***********************************

// free.c
void		ft_free(void *addr);
void		free_data(t_data data);

// ********************************** PARSING *********************************

// parsing.c
int			is_positive_int(int ac, char **av);
int			parsing(int ac, char **av);

// *********************************** PRINT **********************************

// print.c
int			err_msg(char *s1, int ret_val);
int			print_action(t_data *data, int id, char *action, char *color);

// *********************************** UTILS **********************************

// utils.c
int			ft_strlen(char *str);
void		*ft_calloc(size_t n, size_t size);
long		ft_atoi(const char *str);

#endif