/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:56:46 by banne             #+#    #+#             */
/*   Updated: 2025/11/14 13:53:45 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <fcntl.h>

int	check_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlenn(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
		return (0);
	return (1);
}

int	check_file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error("Usage: ./so_long <map.ber>");
		return (0);
	}
	if (!check_extension(argv[1]))
	{
		print_error("Map must have .ber extension");
		return (0);
	}
	if (!check_file_exists(argv[1]))
	{
		print_error("File does not exist or is not readable");
		return (0);
	}
	return (1);
}
