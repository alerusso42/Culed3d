/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:18:26 by edraccan          #+#    #+#             */
/*   Updated: 2024/11/25 11:58:53 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (void *)s1;
	str2 = (void *)s2;
	while (str1[i] != '\0' && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i == 0 && str1[i] == '\0')
		return (str1[i] - str2[i]);
	return (0);
}

/* 
int main()
{
	printf("%d\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7));
	printf("%d\n", memcmp("abcdefghij", "abcdefgxyz", 7));
} */