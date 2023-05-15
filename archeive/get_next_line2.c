#include "get_next_line.h"

int	past_buffer_check( char **NL_chars, char **str)
{
	int		i;
	char	temp[BUFFER_SIZE];

	i = 0;
	while (i < BUFFER_SIZE)
		temp[i++] = '\0';
	i = 0;
	while (*(*NL_chars + i) != '\n' && i < BUFFER_SIZE - 1 && *(*NL_chars+i) != '\0')
		i++;
	ft_strlcpy(temp, *NL_chars, BUFFER_SIZE);
	*(*NL_chars + i + 1) = '\0';
	*str = ft_strjoin(*str, *NL_chars);
	if (i + 1 < BUFFER_SIZE)
		*NL_chars = ft_strjoin(*NL_chars, temp + i + 1);
	if (temp[i] == '\n')
		return (1);
	return(0);
}

char*	read_loop(int fd, char **str)
{
	char    *buffer;
	int     rd;

	buffer = (char *) malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	rd = 1;
	while (rd > 0 && !ft_strchr(*str, '\n'))
	{
		rd = read (fd, buffer, BUFFER_SIZE);
		if ( rd == -1)
		{
			free (buffer);
			return (0);
		}
		buffer[rd] = '\0';
		if (rd)
			*str = ft_strjoin(*str, buffer);
	}
	free(buffer);
	return (*str);
}

void    seperate_append_buffer(char **NL_chars, char** str)
{
	char	*new_line;
	new_line = ft_strchr(*str, '\n');
	*NL_chars = ft_strjoin(*NL_chars, new_line + 1);

	if (new_line != NULL)
		*NL_chars = ft_strjoin(*NL_chars, new_line + 1);
	printf("trace1\n");
}

char* get_next_line (int fd)
{
	char    	*str;
	static char	*NL_chars;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = "";
	printf("yes");
	if (*NL_chars != '\0')
	{
		printf("yes");
		if (past_buffer_check(&NL_chars, &str))
			return (str);
	}
	if (!read_loop(fd, &str))
		return (0);
	if (!(*str))
		return (0);
	// the segf is here

	seperate_append_buffer (&NL_chars, &str);
	printf("trace\n");
	return (str);
}

int main()
{
    int fd = open("giant_line_nl.txt", O_RDWR | O_EXCL);

	char *str;
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
	str = get_next_line(fd);
    printf("%s", str);
    free(str);
	str = get_next_line(fd);
    printf("%s", str);
    free(str);

    close(fd);
}
