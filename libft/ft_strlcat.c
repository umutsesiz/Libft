/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umsesiz <umsesiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:00:30 by umsesiz           #+#    #+#             */
/*   Updated: 2024/11/13 15:55:47 by umsesiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	sizesrc;
	size_t	sizedst;
	size_t	i;
	size_t	k;

	sizesrc = ft_strlen(src);
	sizedst = ft_strlen(dst);
	k = sizedst;
	i = 0;
	if (dstsize <= sizedst)
		return (sizesrc + dstsize);
	while (src[i] != '\0' && k < dstsize - 1)
	{
		dst[k] = src[i];
		k++;
		i++;
	}
	dst[k] = '\0';
	return (sizedst + sizesrc);
}
