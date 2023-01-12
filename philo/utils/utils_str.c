/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:06:01 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/12 19:12:33 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

void	fill(char *str, long long nb, int j)
{
	j--;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (j >= 0 && str[j] != '-')
	{
		str[j] = (nb % 10) + 48;
		nb /= 10;
		j--;
	}
}

char	*ft_itoa(long long n)
{
	long long	nb;
	int			j;
	char		*str;

	nb = n;
	j = 0;
	if (n <= 0)
		j++;
	while (n != 0)
	{
		n /= 10;
		j++;
	}
	str = ft_calloc(j + 1, sizeof(char));
	if (!str)
		return (NULL);
	fill(str, nb, j);
	return (str);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	dup = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	res = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	ft_free(s1);
	return (res);
}
