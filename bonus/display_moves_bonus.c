/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:35:54 by skarim            #+#    #+#             */
/*   Updated: 2024/01/16 16:09:52 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*res;

	count = count_digits(n);
	res = (char *)malloc(sizeof(char) * (count + 1));
	if (!res)
		return (NULL);
	res[count--] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[count--] = (n % 10) + 48;
		n = n / 10;
	}
	return (res);
}

char	*ft_strjoin_moves(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		s3[i] = s1[i];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s2);
	return (s3);
}

void	ft_put_moves(t_game *g)
{
	char	*str;

	str = ft_strjoin_moves("Moves:", ft_itoa(g->player.mv_nbr));
	if (str == NULL)
	{
		write(1, "Error:\nallocation fails!", 24);
		ft_free_game(g);
	}
	ft_put_image_to_window(g, g->wall_xpm, 0, 0);
	ft_put_image_to_window(g, g->wall_xpm, 1, 0);
	ft_put_image_to_window(g, g->wall_xpm, 2, 0);
	mlx_string_put(g->mlx_ptr, g->win_ptr, 5, 10, 0xFF0000, str);
	free(str);
}
