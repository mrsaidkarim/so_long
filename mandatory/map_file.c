/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:24:54 by skarim            #+#    #+#             */
/*   Updated: 2024/01/13 22:33:23 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{ 
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_valide_file(char *file)
{
	int	n;

	n = ft_strlen(file);
	if (n > 4)
	{
		if (ft_strcmp(&file[n-4], ".ber") == 0)
			return (1);
	}
	return (0);
}