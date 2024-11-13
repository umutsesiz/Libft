/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umsesiz <umsesiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:57:58 by umsesiz           #+#    #+#             */
/*   Updated: 2024/11/08 19:11:53 by umsesiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digit(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = (n / 10) * -1;
		i += 2;
	}
	while (n > 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

static size_t	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static int	fill_string(char *str, int n)
{
	int	i;

	i = 0;
	if (n / 10 != 0)
		i = fill_string(str, n / 10);
	else if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = ft_abs(n % 10) + '0';
	i++;
	str[i] = '\0';
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	len;

	len = count_digit(n);
	if (len == 0)
		len = 1;
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	fill_string(ptr, n);
	return (ptr);
}
