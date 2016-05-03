#include "42sh.h"

t_env		*g_head;
hashtable_t	*g_hashtable;

static char	*get_path(void)
{
	t_env	*cpy;

	cpy = g_head;
	while (cpy)
	{
		if (ft_strcmp(cpy->key, "PATH") == 0)
			return (cpy->value);
		cpy = cpy->next;
	}
	return (NULL);
}

void		hash_binaries(void)
{
	char			*value;
	char			**paths;
	int				i;
	struct dirent	*d;
	DIR				*dir;

	g_hashtable = ht_create(2048);
	i = -1;
	paths = ft_strsplit(get_path(), ':');
	while (paths[++i])
	{
		if ((dir = opendir(paths[i])) != 0)
			while ((d = readdir(dir)) != NULL)
			{
				value = ft_strjoin(paths[i], "/");
				value = ft_concat(value, d->d_name, 1);
				ht_set(g_hashtable, d->d_name, value);
				free(value);
			}
		closedir(dir);
	}
	free_double_tab(paths);
}
