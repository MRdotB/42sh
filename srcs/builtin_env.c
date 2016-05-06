/* ************************************************************************** */

#include "bcsh.h"

t_env			*g_head;

static void	help(void)
{
	ft_putendl("Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...];");
	ft_putendl("Set each NAME to VALUE in the environment and run COMMAND.");
	ft_putendl("  -i  start with an empty environment");
	ft_putendl("  -u  remove variable from the environment");
	ft_putendl("  -h  display this help and exit");
	ft_putendl("If no COMMAND, print the resulting environment.");
	//clean all
}

void		bc_env(char **path)
{
	int	i;

	if (path[1] == NULL)
		return (display_env());
	i = 1;
	while (path[i])
	{
		if (*path[i] == '-')
		{
			if (ft_strcmp("-i", path[i]) == 0)
				ft_putendl("empty TMP LIST");
			else if (ft_strcmp("-h", path[i]) == 0)
				return (help());
			else if (ft_strcmp("-u", path[i]) == 0)
			{
				if (path[++i] == NULL)
				{
					bc_error("env: option -u requires an argument");
					return ft_putendl("Try 'env --h' for more information.");
				}
				else if (ft_strindexof(path[i], '=') != -1)
					return bc_error_file("env: Invalid argument cannot unset: ", path[i]);
				else
				{
					ft_putstr("unset from local env ");
					ft_putendl(path[i]);
				}
			}
			else if (ft_strcmp("--", path[i]) == 0)
			{
				i++;
				break;
			}
			else
			{
				bc_error_file("env: invalid option --", path[i] + 1);
				return ft_putendl("Try 'env --h' for more information.");
			}
			i++;
		}
		else
			break ;
	}
	while (path[i])
	{
		if (ft_strindexof(path[i], '=') == -1)
			break ;
		ft_putendl(path[i]);
		i++;
	}
	if (path[i])
	{
		ft_putstr("exec binary ");
		ft_putendl(path[i]);
	}
	else
		ft_putendl("display env modified");
	
}
