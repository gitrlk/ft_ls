/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:21:04 by jecarol           #+#    #+#             */
/*   Updated: 2017/02/03 19:38:14 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_freejoin(char *s1, char *s2)
{
	char *joined;

	if (!s1 || !s2)
		return (NULL);
	joined = ft_strnew((ft_strlen(s1) + ft_strlen(s2)));
	if (!joined)
		return (NULL);
	ft_strcpy(joined, s1);
	ft_strdel(&s1);
	ft_strcat(joined, s2);
	ft_strdel(&s2);
	return (joined);
}
