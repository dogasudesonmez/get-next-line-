/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:08:02 by dsonmez           #+#    #+#             */
/*   Updated: 2024/12/06 20:12:48 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_all(int fd, char *buffer)
{
    int     bytes_read;
    char    *first_buff;

    bytes_read = 1;
    while (!(ft_strchr(buffer, '\n')) && bytes_read != 0)
    {
        first_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!first_buff)
            return  (NULL);
        bytes_read = read(fd, first_buff, BUFFER_SIZE);
        if(bytes_read == -1 || (!buffer && bytes_read == 0))
            return (free(first_buff), NULL);
        first_buff[bytes_read] = '\0';
        buffer = ft_strjoin(buffer, first_buff);
    }
    return (buffer);
}

char *get_line(char *buffer)
{
    char    *line;
    int     i;

    i = 0;
    if(!*buffer)
        return (NULL);
    while(buffer[i] != '\0' && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        i++;
    line = (char *)malloc(sizeof(char) * (i + 1));
    if(!line)
        return(NULL);
    i = 0;
    while(buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char    *get_rest(char *buffer, char *line)
{
    char *rest;
    int i;
    int j;
    
    i = ft_strlen(line);
    if(!buffer[i])
        return (free(buffer), NULL);
    j = 0;
    while(buffer[i++])
        j++;
    rest = (char *)malloc(sizeof(char) * (j + 1));
    if(!rest)
        return (NULL);
    i = ft_strlen(line);
    j = 0;
    while(buffer[i])
        rest[j++] = buffer[i++];
    rest[j] = '\0';
    return (rest);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char        *line;
    
    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    buffer = read_all(fd, buffer);
    if(!buffer)
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    line = get_line(buffer);
    buffer = get_rest(buffer, line);
    return (line);
}