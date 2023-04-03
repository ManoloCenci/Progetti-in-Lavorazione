#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *s)
{
	size_t	a;
	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}
size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	if (!dst || !src)
		return (0);
	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while ((i < dstsize - 1) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

char	*prove(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	finish;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	finish = 0;
	if (start < slen)
		finish = slen - start;
	if (finish > len)
		finish = len;
	new = (char *)malloc(sizeof(char) * (finish + 1));
	if (!new)
		return (0);
	ft_strlcpy(new, s + start, finish + 1);
	return (new);
}

int main()
{
	char a[] = "Ciao come stai";
	printf("%s\n", prove(a, -1, 8));
}