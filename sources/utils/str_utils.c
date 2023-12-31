/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:10:43 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/21 13:58:15 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strclen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	*ft_strldup(char *src, int size)
{
	char	*dst;

	if (!size)
		return (0);
	dst = malloc(sizeof(char) * size);
	if (!dst)
		return (0);
	ft_strlcpy(dst, src, size);
	if (!dst)
		return (0);
	return (dst);
}

size_t	ft_strdlen(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strequals(char *s1, char *s2)
{
	return (s1 && s2 && ft_strlen(s1) == ft_strlen(s2)
		&& !ft_strncmp(s1, s2, ft_strlen(s1)));
}

int	ft_strcontains(char *s1, char *s2)
{
	return (s1 && s2 && !ft_strncmp(s1, s2, ft_strlen(s2)));
}
