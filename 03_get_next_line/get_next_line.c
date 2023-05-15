#include "get_next_line.h"

void shift(char * str, char *ptr)
{
	int	i;
	i = 0;
	while( ptr[i + 1] != '\0' && str[i]!='\0')
	{
		str[i]= ptr[i + 1];
		i++;
	}
	str[i] = '\0';
	return;
}

int	past_buffer_check(char *NL_chars)
{
	char *ptr;
	ptr = ft_strchr(NL_chars, '\n');
	if (!ptr)
		return (0);
	shift(NL_chars, ptr);
	return (1);
}

char*	read_loop(int fd, char **str, char *NL_chars)
{
	int     rd;

	rd = 1;
	rd = read (fd, NL_chars, BUFFER_SIZE);
	if ( rd < 0)
	{
		free (*str);
		return (0);
	}
	NL_chars[rd]='\0';
	while (rd > 0)
	{
		*str = ft_strjoin(*str, NL_chars);
		if(past_buffer_check(NL_chars))
			break;
		rd = read (fd, NL_chars, BUFFER_SIZE);
		NL_chars[rd]='\0';
	}
	return (*str);
}

char* get_next_line (int fd)
{
	char    	*str;
	static char	NL_chars[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || FOPEN_MAX < fd)
		return (0);
	str = ft_strjoin(0, NL_chars);
	if (past_buffer_check(NL_chars))
		return (str);
	if (!read_loop(fd, &str, NL_chars))
		return (0);
	if (!(*str))
		return (0);
	return (str);
}

// int main()
// {
//     int fd = open("read_error.txt", O_RDONLY);

// 	char *str;
//     str = get_next_line(fd);
//     printf("%s", str);
//     free(str);

// 	str = get_next_line(fd);
//     printf("%s", str);
//     free(str);
	
// 	str = get_next_line(fd);
//     printf("%s", str);
//     free(str);
	
// 	str = get_next_line(fd);
//     printf("%s", str);
//     free(str);
	
// 	str = get_next_line(fd);
//     printf("%s", str);
//     free(str);
	
	
//     close(fd);
// }