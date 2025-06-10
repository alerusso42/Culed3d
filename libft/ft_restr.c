/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:03:44 by edraccan          #+#    #+#             */
/*   Updated: 2025/05/03 10:32:12 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// restituisce un dup della stringa nuova freeando old
char	*ft_restr(char *old, char *new)
{
	free(old);
	return (ft_strdup(new));
}
