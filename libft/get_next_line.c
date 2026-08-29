/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:20:41 by agoudet-          #+#    #+#             */
/*   Updated: 2026/08/25 21:14:22 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy_leftovers() - Copy previous leftovers to buffer
static void	copy_leftovers(char *lftov, char *buf, ssize_t *tot_bytes);
// At the first get_next_line() call, the function won't have anything to copy.

// read_content() - Start reading from fd to buffer
static void	read_content(char **buf, int fd, ssize_t *tot_bytes);
// The function dynamically changes the buffer's address as larger memory
// sizes are needed.
//
// Nothing will happen if copy_leftovers copied a newline to buffer.
//
// Also stops whenever nothing was read, this to handle EOF without
// a finishing newline.

// get_line_and_leftovers() - Extract line to return and leftovers from buffer
static void	get_line_and_leftovers(char const *buf, char **line, char **lftov);

// Beginning of get_next_line() structure below
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*leftovers = NULL;
	ssize_t		bytes_loaded;
	char		*line_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	*buffer = '\0';
	bytes_loaded = 0;
	copy_leftovers(leftovers, buffer, &bytes_loaded);
	read_content(&buffer, fd, &bytes_loaded);
	if (bytes_loaded == -1 || bytes_loaded == 0)
	{
		free(buffer);
		return (NULL);
	}
	*(buffer + bytes_loaded) = '\0';
	get_line_and_leftovers(buffer, &line_read, &leftovers);
	free(buffer);
	return (line_read);
}

static void	copy_leftovers(char *lftov, char *buf, ssize_t *tot_bytes)
{
	size_t	ltov_len;

	if (lftov == NULL)
		ltov_len = 0;
	else
	{
		ltov_len = ft_strlen(lftov);
		ft_memcpy(buf, lftov, ltov_len);
		free(lftov);
	}
	*(buf + ltov_len) = '\0';
	*tot_bytes += ltov_len;
}

static void	read_content(char **buf, int fd, ssize_t *tot_bytes)
{
	ssize_t	chunk_bytes;
	char	*buf_dup;
	char	*old_buf;

	chunk_bytes = 1;
	while (ft_strchr(*buf, '\n') == NULL && chunk_bytes != 0)
	{
		buf_dup = ft_strdup(*buf);
		chunk_bytes = read(fd, *buf, BUFFER_SIZE);
		if (chunk_bytes == -1)
		{
			*tot_bytes = chunk_bytes;
			free(buf_dup);
			return ;
		}
		*(*buf + chunk_bytes) = '\0';
		*tot_bytes += chunk_bytes;
		old_buf = *buf;
		*buf = ft_strjoin(buf_dup, *buf);
		free(buf_dup);
		free(old_buf);
	}
}

static void	get_line_and_leftovers(char const *buf, char **line, char **lftov)
{
	size_t	line_len;
	size_t	lftov_len;
	size_t	idx;

	idx = 0;
	while (buf[idx] != '\n' && buf[idx] != '\0')
		idx++;
	if (buf[idx] != '\n')
		line_len = idx;
	else
		line_len = idx + 1;
	*line = ft_substr(buf, 0, line_len);
	lftov_len = ft_strlen(buf + line_len);
	if (lftov_len == 0)
	{
		*lftov = NULL;
		return ;
	}
	*lftov = ft_substr(buf, line_len, lftov_len);
}

// No space for this helper function in utils
char	*ft_strdup(const char *s)
{
	char		*s_dup;
	size_t		len;

	len = ft_strlen(s);
	s_dup = (char *)malloc(len + 1);
	if (s_dup == NULL)
		return (NULL);
	ft_memcpy(s_dup, s, len + 1);
	return (s_dup);
}
