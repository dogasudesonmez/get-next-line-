/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:49:03 by dsonmez           #+#    #+#             */
/*   Updated: 2024/12/06 21:15:49 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	 
	while (s[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*s2;
	size_t	i;
	size_t	k;

	s2 = (char *)s1;
	i = ft_strlen(s2);
	k = 0;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
	{
		return (NULL);
	}
	while (k <= i && s2[k])
	{
		dup[k] = s2[k];
		k++;
	}
	dup[k] = '\0';
	return (dup);
}
char	*ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char *joined;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (s2);
    if (!s2)
        return (s1);
    joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!joined)
        return (NULL);
    while (s1[i])
    {
        joined[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        joined[i + j] = s2[j];
        j++;
    }
    joined[i + j] = '\0';
    return (free(s1), joined);
}
int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
