/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:03:32 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/17 19:17:01 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int			ft_fillinfo(t_ls *info, int checker, char *path)
{
	struct stat		stats;

	lstat(path, &stats);
	info->epoch = stats.st_mtime;
	info->name = ft_strdup(path);
	info->p_d = checker;
	return (0);
}

void		ft_modesetassist(struct stat stats, char *mode)
{
	*mode++ = (stats.st_mode & S_IRUSR ? 'r' : '-');
	*mode++ = (stats.st_mode & S_IWUSR ? 'w' : '-');
	if (stats.st_mode & S_ISUID)
		*mode++ = (stats.st_mode & S_IXUSR ? 's' : 'S');
	else
		*mode++ = (stats.st_mode & S_IXUSR ? 'x' : '-');
	*mode++ = (stats.st_mode & S_IRGRP ? 'r' : '-');
	*mode++ = (stats.st_mode & S_IWGRP ? 'w' : '-');
	if (stats.st_mode & S_ISGID)
		*mode++ = (stats.st_mode & S_IXGRP ? 's' : 'S');
	else
		*mode++ = (stats.st_mode & S_IXGRP ? 'x' : '-');
	*mode++ = (stats.st_mode & S_IROTH ? 'r' : '-');
	*mode++ = (stats.st_mode & S_IWOTH ? 'w' : '-');
	if (stats.st_mode & S_ISVTX)
		*mode++ = (stats.st_mode & S_IXUSR ? 't' : 'T');
	else
		*mode = (stats.st_mode & S_IXOTH ? 'x' : '-');
}

void		ft_modeset(struct stat stats, char *mode)
{
	if (S_ISCHR(stats.st_mode))
		*mode++ = 'c';
	else if (S_ISFIFO(stats.st_mode))
		*mode++ = 'p';
	else if (S_ISDIR(stats.st_mode))
		*mode++ = 'd';
	else if (S_ISLNK(stats.st_mode))
		*mode++ = 'l';
	else if (S_ISBLK(stats.st_mode))
		*mode++ = 'b';
	else if (S_ISSOCK(stats.st_mode))
		*mode++ = 's';
	else if (S_ISREG(stats.st_mode))
		*mode++ = '-';
	ft_modesetassist(stats, mode);
}

void		ft_getinfonewpath(char *path, char **newpath, char *name)
{
	char	*tmp;

	if (path[0] == '.' && path[1] == '\0')
		*newpath = ft_strdup(name);
	else
	{
		tmp = ft_strjoin(path, "/");
		*newpath = ft_strjoin(tmp, name);
		free(tmp);
	}
}

void		ft_getdatefromepoch(time_t epoch, char **date)
{
	char	*tmp1;
	char	*tmp2;
	time_t	ajd;

	time(&ajd);
	tmp1 = ctime(&epoch);
	if ((ajd - 15778463) > epoch || ajd < epoch)
	{
		tmp2 = ft_strnew(6);
		tmp2 = ft_strsub(tmp1, 20, 4);
		tmp1 = ft_strsub(tmp1, 4, 6);
		tmp1 = ft_strjoin(tmp1, "  ");
		tmp1 = ft_strjoin(tmp1, tmp2);
		free(tmp2);
	}
	else
		tmp1 = ft_strsub(tmp1, 4, 12);
	tmp1[12] = '\0';
	*date = ft_strdup(tmp1);
	free(tmp1);
}
