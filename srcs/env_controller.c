#include "42sh.h"

t_env	*head;
extern char	**environ;

t_env	*new_elem(char *env)
{
	t_env	*r;
	char	*key;
	char	*value;
	int		equal_pos;

	equal_pos = ft_strindexof(env, '=');
	if (!(r = ft_memalloc(sizeof(*r))) || equal_pos == -1)
		return (NULL);
	if (!(key = ft_strnew(equal_pos)))
		return (NULL);
	value = ft_strdup(env + equal_pos);
	r->key = ft_strncpy(key, env, equal_pos - 1);
	r->value = value;
	r->next = NULL;
	return (r);
}

t_env	*push_front(t_env *lst, t_env *el)
{
	if (lst == NULL)
		return (el);
	else
		el->next = lst;
	return (el);
}

void	clean_env(void)
{
	t_env	*tmp;
	while (head)
	{
		free(head->key);
		free(head->value);
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	display_env(void)
{
	t_env	*cpy;

	cpy = head;
	while (cpy)
	{
		ft_putstr(cpy->key);
		ft_putchar('=');
		ft_putendl(cpy->value);
		cpy = cpy->next;
	}
}

void	set_env(char *key, char *value, int overwrite)
{
	t_env	*cpy;

	cpy = head;
	while (cpy)
	{
		if (overwrite && ft_strcmp(cpy->key, key) == 0)
		{
			free(cpy->value);
			cpy->value = ft_strdup(value);
			return ;
		}
		cpy = cpy->next;
	}
	if (!(cpy = ft_memalloc(sizeof(*cpy))))
		return ;
	cpy->key = ft_strdup(key);
	cpy->value = ft_strdup(value);
	cpy->next = head;
	head = cpy;
}

void	get_env(char *key)
{
	t_env	*cpy;

	cpy = head;
	while (cpy)
	{
		if (ft_strcmp(cpy->key, key) == 0)
		{
			ft_putendl(cpy->value);
			return ;
		}
		cpy = cpy->next;
	}
}

void	unset_env(char *key)
{
	t_env	*cpy;
	t_env	*prev;

	cpy = head;
	prev = NULL;
	while (cpy)
	{
		if (ft_strcmp(cpy->key, key) == 0)
		{
			if (prev == NULL)
				head = head->next;
			else
				prev->next = cpy->next;
			free(cpy->key);
			free(cpy->value);
			free(cpy);
			return ;
		}
		prev = cpy;
		cpy = cpy->next;
	}
}

char	**env_to_tab(void)
{
	t_env	*cpy;
	int		i;
	char	**r;
	char	*el;

	cpy = head;
	i = 0;
	while (cpy)
	{
		i++;
		cpy = cpy->next;
	}
	cpy = head;
	if (!(r = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (cpy)
	{
		el = ft_strjoin(cpy->key, "=");
		el = ft_concat(el, cpy->value, 1);
		r[i++] = el;
		cpy = cpy->next;
	}
	return (r);
}

void	env_init(void)
{
	int		i;

	head = NULL;
	i = 0;
	while (environ[i])
		i++;
	while (i > 0)
		head = push_front(head, new_elem(environ[--i]));
	set_env("testttt", "value", 1);
	set_env("carlos", "lol", 1);
	get_env("carlos");
	unset_env("carlos");
	unset_env("testttt");
	display_env();

	clean_env();
}
