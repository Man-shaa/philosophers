/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:28:17 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/27 18:22:01 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*tab;
	char	*str;

	tab = malloc(n * size);
	if (!tab)
		return (NULL);
	str = tab;
	while (n > 0)
	{
		n--;
		str[n] = '\0';
	}
	return (tab);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (0);
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}
