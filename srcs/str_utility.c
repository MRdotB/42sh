
#include "bcsh.h"

char	*tilde_replace(char *src)
{
	char	*home;

	home = get_env("HOME");
	if (home == NULL || src == NULL)
		return (src);
	if (ft_strcmp("~", src) == 0)
		return (ft_strdup(home));
	if (ft_strncmp("~", src, 1) == 0)
		return (ft_concat(home, src + 1, 0));
	return (src);
}
