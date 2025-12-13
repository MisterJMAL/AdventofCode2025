/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Day_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrJMAL <jleclerc@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:34:33 by jleclerc          #+#    #+#             */
/*   Updated: 2025/12/13 13:31:25 by MrJMAL           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft_42/libft.h"
#include <fcntl.h>

int	*ft_range(int a, int b)
{
	int	*range;
	int	i;
	
	range = malloc((b - a + 1) * sizeof(int));
	if (!range)
		return (NULL);
	i = 0;
	while (a < b + 1)
		range[i++] = a++;
	range[i] = '\0';
	return (range);
}



int	main(void)
{
	int i;
	int	len;
	int	*range;
	char	**split;
	char	*line;
	int		fd;

	fd = open("ID-Checks.txt", O_RDONLY);
	line = get_next_line(fd);
	split = ft_split(line, ',');
	close(fd);
	return (0);
}
