/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Day_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 11:10:25 by jleclerc          #+#    #+#             */
/*   Updated: 2025/12/25 12:38:00 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft_42/libft.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	fd = open("Fresh.txt", O_RDONLY);
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