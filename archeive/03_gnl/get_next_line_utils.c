
#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		num;

	if (s2[0] == '\0')
		return (NULL);
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) +1) * sizeof(char));
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	num = 0;
	while (s1 && s1[num])
	{
		ptr[num] = s1[num];
		num++;
	}
	while (s2 && *s2 && *s2 != '\n')
		ptr[num++] = *s2++;
	if (*s2 == '\n')
		ptr[num++] = '\n';
	ptr[num] = '\0';
	if (s1)
		free(s1);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str && *str)
	{
		count++;
		if (*str == '\n')
			break ;
		str++;
	}
	return (count);
}