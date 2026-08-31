/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:17:10 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/31 15:52:25 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file_handler.h"
#include "ft_string.h"
#include <unistd.h>

FT_FILE	ft_open(char *path, char *modes)
{
	char	**file_names;
	FT_FILE	*file;

	if (ft_strlen(path) >= PATH_MAX)
		return (NULL);
	file_names = ft_split(path, "/");
	if (file_names == NULL)
		ft_putstr("Warning: Failed to check the path, going on anyways.\n");
	else
	{
		while (*file_names)
		{
			if (ft_strlen(*file_names) > FILE_NAME_MAX)
				return (NULL);
			file_names++;
		}
	}
	free(file_names);
	if (!(*modes))
		return (-1);
	if (ft_strlen(modes) != 2)
		return (-1);
	file = (FT_FILE *)malloc(sizeof(FT_FILE));
	if (file == NULL)
		return (NULL);
	if (ft_str_contains('w', modes) > -1 && ft_str_contains('r', modes) > -1)
		file->fd = open(path, O_RDWR);
	else if (ft_str_contains('w', modes) > -1)
		file->fd = open(path, O_WRONLY);
	else if (ft_str_contains('r', modes) > -1)
		file->fd = open(path, O_RDONLY);
	file->buffer = NULL;
	file->offset = 0;
	file->size = 0;
	if (file->id == -1)
	{
		free(file);
		return (NULL);
	}
	return (file);
}

int	ft_read(unsigned int size, char *buffer, FT_FILE file)
{
	int	bytes_read;

	if (file == NULL)
		return (-1);
	if (file->fd == -1)
		return (-1);
	if (buffer != NULL)
		free(buffer);
	buffer = malloc(sizeof(char) * size);
	if (file->buffer == NULL)
		return (-1);
	bytes_read = read(file->fd, buffer, size);
	file->offset += bytes_read;
	if (file->offset > file->size)
		file->size = file->offset;
	return (bytes_read);
}

int	ft_write(unsigned int size, char *buffer, FT_FILE file)
{
	int	bytes_written;

	if (file == NULL)
		return (-1);
	if (file->fd == NULL)
		return (-1);
	bytes_written = write(file->fd, buffer, size);
	if (bytes_written == -1)
		return (bytes_written);
	file->offset += bytes_written;
	if (file->offset > file->length)
		file->size = file->offset;
	return (bytes_written);
}

int	ft_close(FT_FILE file)
{
	int	ret;

	if (file == NULL)
		return (-1);
	if (file->fd == -1)
		return (-1);
	ret = close(file->fd);
	if (ret != -1)
	{
		if (file->buffer != NULL)
			free(file->buffer);
		free(file);
	}
	return (ret);
}

int	ft_prep_file(FT_FILE *file)
{
	char	c;

	if (file == NULL)
		return (-1);
	if (file->fd == -1)
		return (-1);
	read(file->fd, &c, 1);
	while (c != EOF)
	{
		file->length++;
		file->offset++;
		read(file->fd, &c, 1);
	}
	file->offset = 0;
	file->buffer = (char *)malloc(sizeof(char) * file->length + 1);
	
	return (0);
}
