/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 17:32:05 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/14 22:54:03 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_list				*ft_sort(t_list *lst)
{
	t_list			*m1;
	t_list			*m2;
	t_list			tmp;

	m1 = lst;
	while (m1)
	{
		m2 = m1->next;
		while (m2)
		{
			if ((sort_ascii((((t_ls*)m1->content)->name),
			(((t_ls*)m2->content)->name)) != 1))
			{
				tmp.content = m1->content;
				m1->content = m2->content;
				m2->content = tmp.content;
			}
			m2 = m2->next;
		}
		m1 = m1->next;
	}
	return (lst);
}

t_list				*ft_sort_rev(t_list *lst)
{
	t_list			*m1;
	t_list			*m2;
	t_list			tmp;

	m1 = lst;
	while (m1)
	{
		m2 = m1->next;
		while (m2)
		{
			if ((sort_rev_ascii((((t_ls*)m1->content)->name),
			(((t_ls*)m2->content)->name))) != 1)
			{
				tmp.content = m1->content;
				m1->content = m2->content;
				m2->content = tmp.content;
			}
			m2 = m2->next;
		}
		m1 = m1->next;
	}
	return (lst);
}

void				ft_ascii_if_same_time(t_list *m1, t_list *m2, t_list tmp,
					int i)
{
	if (i == 1)
	{
		if (sort_ascii((((t_ls*)m1->content)->name),
		(((t_ls*)m2->content)->name)))
		{
			tmp.content = m1->content;
			m1->content = m2->content;
			m2->content = tmp.content;
		}
	}
	else if (i == 0)
	{
		if ((sort_ascii((((t_ls*)m1->content)->name),
		(((t_ls*)m2->content)->name)) != 1))
		{
			tmp.content = m1->content;
			m1->content = m2->content;
			m2->content = tmp.content;
		}
	}
}

t_list				*ft_sort_time(t_list *lst)
{
	t_list			*m1;
	t_list			*m2;
	t_list			tmp;

	m1 = lst;
	while (m1)
	{
		m2 = m1->next;
		while (m2)
		{
			if ((((t_ls*)m1->content)->epoch) < (((t_ls*)m2->content)->epoch))
			{
				tmp.content = m1->content;
				m1->content = m2->content;
				m2->content = tmp.content;
			}
			if ((((t_ls*)m1->content)->epoch) == (((t_ls*)m2->content)->epoch))
				ft_ascii_if_same_time(m1, m2, tmp, 0);
			m2 = m2->next;
		}
		m1 = m1->next;
	}
	return (lst);
}

t_list				*ft_sort_time_rev(t_list *lst)
{
	t_list			*m1;
	t_list			*m2;
	t_list			tmp;

	m1 = lst;
	while (m1)
	{
		m2 = m1->next;
		while (m2)
		{
			if ((((t_ls*)m1->content)->epoch) > (((t_ls*)m2->content)->epoch))
			{
				tmp.content = m1->content;
				m1->content = m2->content;
				m2->content = tmp.content;
			}
			if ((((t_ls*)m1->content)->epoch) == (((t_ls*)m2->content)->epoch))
				ft_ascii_if_same_time(m1, m2, tmp, 1);
			m2 = m2->next;
		}
		m1 = m1->next;
	}
	return (lst);
}
