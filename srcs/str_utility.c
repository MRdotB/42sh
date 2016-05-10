
#include "bcsh.h"

static char	*tilde_replace(t_cfg *cfg, char *src)
{
	char	*home;
	char	*r;

	home = get_env(cfg->env, "HOME");
	if (home == NULL || src == NULL)
		return (src);
	if (ft_strcmp("~", src) == 0)
	{
		free(src);
		return (ft_strdup(home));
	}
	if (ft_strncmp("~", src, 1) == 0)
	{
		r = ft_concat(home, src + 1, 0);
		free(src);
		return (r);
	}
	return (src);
}

char		**av_parse(t_cfg *cfg, char	**av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		av[i] = tilde_replace(cfg, av[i]);
		i++;
	}
	return (av);
}
