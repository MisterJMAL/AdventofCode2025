/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Day_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:34:33 by jleclerc          #+#    #+#             */
/*   Updated: 2025/12/11 18:28:02 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft_42/libft.h"
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		nb;
	int		signe;
	int		count;
	int		add;
	int		i;

	fd = open("Combinaison.txt", O_RDONLY);
	line = get_next_line(fd);
	nb = 50;
	count = 0;
	while (line != NULL)
	{
		signe = 1;
		if (line[0] == 'L')
			signe = -1;
		line[0] = '0';
		add = ft_atoi(line) * signe;
		i = 0;
		if (signe == 1)
		{
			while (i < add)
			{
				nb = (nb + 1) % 100;
				if (nb == 0)
					count++;
				i++;
			}
		}
		else
		{
			while (i > add)
			{
				nb = (nb - 1) % 100;
				if (nb == 0)
					count++;
				i--;
			}
		}
		line = get_next_line(fd);
	}
	close(fd);
	ft_printf("NB = %i\nPassword = %i\n", nb, count);
}
