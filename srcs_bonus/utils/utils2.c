/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:19:11 by banne             #+#    #+#             */
/*   Updated: 2025/11/17 09:19:36 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	count_digits(long nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*rotate(char *s)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s);
	if (s[0] == '-')
		start = 1;
	if (end <= 1)
		return (s);
	while (start < end)
	{
		ft_swap(&s[start], &s[end - 1]);
		start++;
		end--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	int		i;

	i = 0;
	nbr = n;
	str = malloc(count_digits(nbr) + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[i++] = '0';
	while (nbr > 0)
	{
		str[i++] = (char)((nbr % 10) + '0');
		nbr /= 10;
	}
	str[i] = '\0';
	rotate(str);
	return (str);
}
