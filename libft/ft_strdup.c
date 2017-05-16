/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:36:32 by jecarol           #+#    #+#             */
/*   Updated: 2017/02/11 17:36:33 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	if (!(result = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	j = (ft_strlen(s1));
	while (j >= 0)
	{
		result[i] = s1[i];
		i++;
		j--;
	}
	return (result);
}
