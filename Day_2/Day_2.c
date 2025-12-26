/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Day_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:34:33 by jleclerc          #+#    #+#             */
/*   Updated: 2025/12/26 14:53:33 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft_42/libft.h"
#include <fcntl.h>

long long	*ft_range(int a, int b)
{
	long long	*range;
	int	i;
	
	range = malloc((b - a + 2) * sizeof(long long));
	if (!range)
		return (NULL);
	i = 0;
	while (a < b + 1)
		range[i++] = a++;
	range[i] = -1;
	return (range);
}

long long ft_check(char *range_ID)
{
	long long	count;
	char	**splited;
	long long	*range;
	int	i;
	int	j;
	int	k;
	char	*nb;

	splited = ft_split(range_ID, '-');
	range = ft_range(ft_atoi(splited[0]), ft_atoi(splited[1]));
	free(splited[0]);
	free(splited[1]);
	free(splited);
	i = 0;
	count = 0;
	while (range[i] != -1)
	{
		nb = ft_itoa(range[i]);
		j = 0;
		k = ft_strlen(nb) / 2;
		while (k < (int) ft_strlen(nb))
		{
			if (nb[j] != nb[k])
				break;
			j++;
			k++;
		}
		if ((k == (int) ft_strlen(nb)) && ((k - 1) % 2 != 0))
			count += range[i];
		i++;
	}
	free(range);
	return (count);
}

int	main(void)
{
	int		i;
	char	**split;
	char	*line;
	int		fd;
	long long	count;

	fd = open("ID-Checks.txt", O_RDONLY);
	line = get_next_line(fd);
	split = ft_split(line, ',');
	i = 0;
	count = 0;
	while (split[i] != NULL)
	{
		count += ft_check(split[i]);
		i++;
	}
	ft_printf("Count = %d\n", count);
	close(fd);
	return (0);
}
