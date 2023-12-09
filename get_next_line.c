/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:59:04 by ebouboul          #+#    #+#             */
/*   Updated: 2023/12/09 01:29:37 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	line = NULL;
	if (fd < 0 || (size_t)BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	stash = stash_filling(fd, stash, buffer);
	if (*stash == 0)
	{
		free(stash);
		return (stash = 0);
	}
	line = extract_line(stash, line);
	stash = extract_new_stash(stash);
	return (line);
}

char	*stash_filling(int fd, char *stash, char *buffer)
{
	ssize_t	nbytes;

	nbytes = 1;
	if (!stash)
		stash = ft_strdup("");
	while (nbytes > 0)
	{
		nbytes = read(fd, buffer, (size_t)BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbytes] = 0;
		stash = ft_strjoin(stash, buffer);
		if ((ft_strchr(buffer, '\n')))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*extract_new_stash(char *stash)
{
	int		len;
	int		i;
	char	*new_stash;

	len = 0;
	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[len] != '\n' && stash[len])
		len++;
	if (stash[len] == '\n')
		len++;
	new_stash = malloc((ft_strlen(stash) - len + 1) * sizeof(char));
	if (!new_stash)
		return (NULL);
	while (stash[len + i])
	{
		new_stash[i] = stash[len + i];
		i++;
	}
	free(stash);
	new_stash[i] = 0;
	return (new_stash);
}

char	*extract_line(char *stash, char *line)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[len] != '\n' && stash[len])
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(((size_t)len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

// int main()
// {
// 	char *line;
// 	int fd = open("42", O_RDWR);

// 		printf("%s" ,get_next_line(fd));

// 	close(fd);
// }