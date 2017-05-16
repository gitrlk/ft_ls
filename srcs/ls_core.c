/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 17:17:40 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/17 21:14:16 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int					ft_check_dirlist(t_list *dirlist)
{
	t_list			*tmp;
	int				i;

	i = 0;
	tmp = dirlist;
	while (tmp)
	{
		if ((((t_ls*)tmp->content)->name))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void				ft_lsback(t_list *validargs, char *flags, t_checks vals)
{
	t_list			*dirlist;
	t_list			*filelist;
	int				totalcheck;

	totalcheck = 0;
	filelist = ft_createfilelist(validargs);
	if (filelist)
	{
		totalcheck = 1;
		filelist = sort_parser(filelist, flags);
		vals.checker = ft_set_checker(filelist);
		ft_printfilelist(filelist, flags, &vals, totalcheck);
	}
	vals.dont = ft_check_if_dont(filelist);
	dirlist = ft_createdirlist(validargs, &vals);
	dirlist = sort_parser(dirlist, flags);
	vals.empty = ft_check_dirlist(dirlist);
	if (vals.empty > 1)
		vals.dont = 0;
	while (dirlist)
	{
		ft_lookindir((((t_ls*)dirlist->content)->name), flags, vals);
		vals.checker++;
		dirlist = dirlist->next;
	}
}

int					ft_morethanone(t_list *validargs)
{
	t_list			*tmp;
	int				i;

	i = 0;
	tmp = validargs;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int					ft_ls(char *flags, t_list *arglist)
{
	t_list			*validargs;
	t_list			*tmperror;
	static t_checks	vals;

	vals.checker = 0;
	tmperror = arglist;
	if (tmperror)
	{
		ft_sort(tmperror);
		ft_arglistchecker(tmperror, &vals.checker);
	}
	validargs = ft_getvalidargs(arglist);
	validargs = sort_parser(validargs, flags);
	vals.morethanone = ft_morethanone(validargs);
	vals.firstnewline = 0;
	ft_lsback(validargs, flags, vals);
	return (0);
}

void				getflags(char *flags, char *content)
{
	int				flag_nbr;

	flag_nbr = ft_strlen(flags);
	while (*content)
	{
		if (ft_strchr(MACROFLAGS, *content))
		{
			if (!(ft_strchr(flags, *content)))
				flags[flag_nbr++] = *content;
			content++;
		}
		else
			ft_error(1, content);
	}
}
