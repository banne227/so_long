/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:51:42 by banne             #+#    #+#             */
/*   Updated: 2025/10/28 10:13:22 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_buffer(char *buffer)
{
	if (buffer)
		free(buffer);
	return (NULL);
}

static	char	*get_rest(char *rest, int fd)
{
	char		*buffer;
	ssize_t		char_read;
	char		*tmp;	

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (rest);
	char_read = read(fd, buffer, BUFFER_SIZE);
	while (char_read > 0)
	{
		buffer[char_read] = '\0';
		tmp = ft_strjoin(rest, buffer);
		free(rest);
		rest = tmp;
		if (!rest)
			return ((free_buffer(buffer)));
		if (ft_strchr(rest))
			break ;
		char_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (char_read == -1)
		return (free_buffer(rest));
	return (rest);
}

char	*get_new_rest(char *rest)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strchr(rest))
		tmp = ft_strdup(ft_strchr(rest) + 1);
	free(rest);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*rest;	
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (rest)
		{
			free(rest);
			rest = NULL;
		}
		return (NULL);
	}
	rest = get_rest(rest, fd);
	if (!rest || *rest == '\0')
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = fill_line(rest);
	if (!line)
		return (NULL);
	rest = get_new_rest(rest);
	return (line);
}

//int	main(void)
//{
//    int fd = open("test.txt", O_RDONLY);
//    char *line;
//	int i = 1;

//	//line = get_next_line(fd);
//	//printf("Line %d    ", i++);
//    //printf("%s", line);
//    //free(line);
//    while ((line = get_next_line(fd)))
//    {
//		printf("Line %d    ", i++);
//        printf("%s", line);
//        free(line);
//    }
//	printf("\nLine %d    ", i++);
//	printf("%s", get_next_line(fd));
//    close(fd);
//    return (0);
//}