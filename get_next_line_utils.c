/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:59:56 by ebouboul          #+#    #+#             */
/*   Updated: 2023/12/09 00:59:29 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (*s == 0)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		ft_strdup(s2);
	if (s1 && !s2)
		ft_strdup(s1);
	i = 0;
	j = 0;
	tab = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = 0;
	free((void *)(s1));
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*tab;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (malloc(1));
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	tab = malloc(sizeof(char) * (len) + 1);
	if (!tab)
		return (NULL);
	while (len > 0)
	{
		tab[i++] = s[start++];
		len--;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;
	size_t	len;

	if (s1 == 0)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
