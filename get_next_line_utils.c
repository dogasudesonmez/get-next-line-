/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:49:03 by dsonmez           #+#    #+#             */
/*   Updated: 2024/11/24 22:06:53 by dsonmez          ###   ########.fr       */
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
char	*ft_strjoin(const char *s1,const char *s2)
{
	char	*start;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	start = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (start);
}

size_t	ft_strchr(const char *s)
{
    int i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
