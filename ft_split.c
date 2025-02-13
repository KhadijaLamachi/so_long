#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	ptr = malloc((slen + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < slen)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *)(ptr));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	sublen;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sublen = ft_strlen(s) - start;
	if (sublen > len)
		sublen = len;
	ptr = malloc(sizeof(char) * (sublen + 1));
	if (!ptr)
		return (NULL);
	while (i < sublen)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}



static int	count_words(const char *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		else if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	ft_free(char ***ptr, int k)
{
	while (k--)
		free((*ptr)[k]);
	free(*ptr);
	*ptr = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	ptr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (k < count_words(s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		ptr[k++] = ft_substr(s, i, j);
		if (!ptr[k - 1])
			return (ft_free(&ptr, k), NULL);
		i = i + j;
	}
	return (ptr[k] = NULL, ptr);
}


#include <stdio.h>

int main(void)
{
    char **split = ft_split("Hello world 42", ' ');
    int i = 0;

    while (split[i])
    {
        printf("%s\n", split[i]);
        free(split[i]);
        i++;
    }
    free(split);
    return (0);
}
