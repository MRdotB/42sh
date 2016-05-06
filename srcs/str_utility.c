
#include "bcsh.h"

static char	*tilde_replace(char *src)
{
	char	*home;
	char	*r;

	home = get_env("HOME");
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

char		**av_parse(char	**av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		av[i] = tilde_replace(av[i]);
		i++;
	}
	return (av);
}
