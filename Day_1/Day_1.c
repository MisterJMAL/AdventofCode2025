/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Day_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:34:33 by jleclerc          #+#    #+#             */
/*   Updated: 2025/12/11 17:53:20 by jleclerc         ###   ########.fr       */
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
		nb = (nb + (ft_atoi(line) * signe));
		if (nb == 0)
			count++;
		if (nb < 0)
		{
			while (nb < 0)
			{
				nb += 100;
				count++;
			}
		}
		else
		{
			while (nb > 99)
			{
				nb -= 100;
				count++;
			}
		}
		line = get_next_line(fd);
	}
	close(fd);
	ft_printf("Password = %i\n", count);
}
