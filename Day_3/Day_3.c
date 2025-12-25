/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Day_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 11:10:25 by jleclerc          #+#    #+#             */
/*   Updated: 2025/12/25 12:14:26 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft_42/libft.h"
#include <fcntl.h>

typedef struct max
{
	char	maximum;
	int		i;
}			maxi;

maxi	ft_max(char *line, int start)
{
	maxi	max;

	max.i = start;
	max.maximum = line[start];
	while (line[start])
	{
		if (max.maximum < line[start])
		{
			max.maximum = line[start];
			max.i = start;
		}
		start++;
	}
	return (max);
}

maxi	ft_max2(char *line, int start)
{
	maxi	max;
	maxi	max2;

	max = ft_max(line, 0);
	max2.i = start;
	max2.maximum = line[start];
	while (start < max.i)
	{
		if (max2.maximum < line[start])
		{
			max2.maximum = line[start];
			max2.i = start;
		}
		start++;
	}
	return (max2);
}

int	ft_searchmax(char *line)
{
	int		nb;
	maxi	max1;
	maxi	max2;
	
	max1 = ft_max(line, 0);
	if (max1.i + 2 != (int)ft_strlen(line))
		max2 = ft_max(line, max1.i + 1);
	else{
		max2 = ft_max2(line, 0);}
	if (max1.i < max2.i)
		nb = atoi(&max1.maximum) * 10 + atoi(&max2.maximum);
	else
		nb = atoi(&max2.maximum) * 10 + atoi(&max1.maximum);
	return (nb);
	
}

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	fd = open("Gen.txt", O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count += ft_searchmax(line);
		line = get_next_line(fd);
	}
	ft_printf("Count = %d\n", count);
	close(fd);
	return (0);
}