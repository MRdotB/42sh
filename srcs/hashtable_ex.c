#include "hashtable.h"
#include "libft.h"

entry_t		*ht_newpair(char *key, char *value)
{
	entry_t *newpair;

	if ((newpair = malloc(sizeof(entry_t))) == NULL)
		return (NULL);
	if ((newpair->key = ft_strdup(key)) == NULL)
		return (NULL);
	if ((newpair->value = ft_strdup(value)) == NULL)
		return (NULL);
	newpair->next = NULL;
	return (newpair);
}

static void	ht_set_ex(entry_t *newpair, entry_t *next, entry_t *last)
{
	if (next == NULL)
		last->next = newpair;
	else
	{
		newpair->next = next;
		last->next = newpair;
	}
}

void		ht_set(hashtable_t *hashtable, char *key, char *value)
{
	int		bin;
	entry_t	*newpair;
	entry_t	*next;
	entry_t	*last;

	bin = ht_hash(hashtable, key);
	next = hashtable->table[bin];
	while (next != NULL && next->key != NULL && ft_strcmp(key, next->key) > 0)
	{
		last = next;
		next = next->next;
	}
	if (next != NULL && next->key != NULL && ft_strcmp(key, next->key) == 0)
	{
		free(next->value);
		next->value = ft_strdup(value);
		return ;
	}
	if ((newpair = ht_newpair(key, value)) && next == hashtable->table[bin])
	{
		newpair->next = next;
		hashtable->table[bin] = newpair;
	}
	else
		ht_set_ex(newpair, next, last);
}

char		*ht_get(hashtable_t *hashtable, char *key)
{
	int		bin;
	entry_t	*pair;

	bin = ht_hash(hashtable, key);
	pair = hashtable->table[bin];
	while (pair != NULL && pair->key != NULL && ft_strcmp(key, pair->key) > 0)
		pair = pair->next;
	if (pair == NULL || pair->key == NULL || ft_strcmp(key, pair->key) != 0)
		return (NULL);
	else
		return (pair->value);
}
