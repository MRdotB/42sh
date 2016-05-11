/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:38:43 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/11 17:38:45 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_in(char c, char *s)
{
	while (*s)
		if (c == *s)
			return (1);
		else
			s++;
	return (0);
}

static size_t	ft_wordcount(char const *s, char *c)
{
	int		in_word;
	size_t	n_word;
	size_t	i;

	in_word = 0;
	n_word = 0;
	i = 0;
	while (s[i])
	{
		if (is_in(s[i], c) == 0)
		{
			if (!in_word)
				n_word++;
			in_word = 1;
		}
		else
			in_word = 0;
		i++;
	}
	return (n_word);
}

static char		*ft_wordpicker(char *str, char **ptr, char *c)
{
	size_t	word_begin;
	size_t	word_end;
	char	*word;

	word_begin = 0;
	word_end = 0;
	while (is_in(str[word_begin], c))
		word_begin++;
	word_end = word_begin;
	while (str[word_end] && !is_in(str[word_end], c))
		word_end++;
	word = ft_strsub(str, word_begin, word_end - word_begin);
	*ptr = word;
	return (str + word_end);
}

char			**ft_strsplitstr(char const *s, char *c)
{
	size_t	n_word;
	char	**ptr;
	char	*str;
	size_t	i;

	ptr = NULL;
	i = 0;
	if (s)
	{
		str = (char*)s;
		n_word = ft_wordcount(s, c);
		ptr = (char**)ft_memalloc((n_word + 1) * sizeof(char*));
		if (!ptr)
			return (NULL);
		while (i < n_word)
			str = ft_wordpicker(str, ptr + i++, c);
		ptr[n_word] = 0;
	}
	return (ptr);
}
