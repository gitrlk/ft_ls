/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:05:40 by jecarol           #+#    #+#             */
/*   Updated: 2017/04/14 23:50:22 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int					ft_fillassist(t_ls *info, char *path)
{
	char			buf[MAXFILENAMELEN + 1];
	ssize_t			ret;
	int				majorvalue;
	struct stat		sym_stat;

	majorvalue = 0;
	ret = 0;
	ft_bzero(&buf, MAXFILENAMELEN + 1);
	ret = readlink(path, buf, MAXFILENAMELEN);
	info->linkpath = (ret == -1 ? NULL : ft_strdup(buf));
	info->major = -1;
	if (info->mode[0] == 'c' || info->mode[0] == 'b')
	{
		stat(path, &sym_stat);
		majorvalue = sym_stat.st_rdev;
		while ((majorvalue / 256) > 0)
			majorvalue = majorvalue / 256;
		info->size = sym_stat.st_rdev % 256;
		info->major = majorvalue;
	}
	ft_memdel((void**)&path);
	return (0);
}

int					ft_filleleminfo(char *element, char *path,
					t_ls *info, int slash)
{
	struct passwd	*pwd;
	struct group	*grp;
	struct stat		stats;

	info->path = ft_strdup(element);
	info->name = ft_strdup(element);
	if (slash)
		path = ft_strjoin(".", path);
	lstat(path, &stats);
	ft_modeset(stats, info->mode);
	pwd = getpwuid(stats.st_uid);
	grp = getgrgid(stats.st_gid);
	info->links = stats.st_nlink;
	info->owner = ft_strdup(pwd->pw_name);
	info->group = ft_strdup(grp->gr_name);
	info->size = stats.st_size;
	info->bloks = stats.st_blocks;
	info->epoch = stats.st_mtime;
	ft_getdatefromepoch(info->epoch, &info->date);
	return (ft_fillassist(info, path));
}

int					ft_fillfileinfo(t_ls *info, struct dirent *infostruct,
					char *path)
{
	struct stat		stats;
	struct passwd	*pwd;
	struct group	*grp;

	info->path = ft_strdup(path);
	ft_getinfonewpath(info->path, &info->newpath, infostruct->d_name);
	lstat(info->newpath, &stats);
	ft_modeset(stats, info->mode);
	pwd = getpwuid(stats.st_uid);
	grp = getgrgid(stats.st_gid);
	info->name = ft_strdup(infostruct->d_name);
	info->type = infostruct->d_type;
	info->links = stats.st_nlink;
	info->owner = ft_strdup(pwd->pw_name);
	info->group = ft_strdup(grp->gr_name);
	info->size = stats.st_size;
	info->bloks = stats.st_blocks;
	info->epoch = stats.st_mtime;
	ft_getdatefromepoch(info->epoch, &info->date);
	return (ft_fillassist(info, info->newpath));
}
