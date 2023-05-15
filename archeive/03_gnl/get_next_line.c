#include "get_next_line.h"

int	find_NL( char *str)
{
	int	i;
	int	j;
	int flag;
	
	i = 0;
	j = 0;
	flag = 0;

	while(str[i])
	{
		if (flag)
			str[j++]=str[i++];
		if (str[i] == '\n')
			flag = 1;
		str[i++] = '\0';
	}
	return(flag);
}

char*	read_loop(int fd, char *NL_chars, char **str)
{
	int     rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read (fd, NL_chars, BUFFER_SIZE);
		if ( rd == -1)
		{
			free (*str);
			return (0);
		}
		if (rd > 0)
		{
			*str = ft_strjoin(*str, NL_chars);
			if(find_NL(NL_chars))
				break;
		}
	}
	return (*str);
}

char* get_next_line (int fd)
{
	char    	*str;
	static char NL_chars[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (0);
	
	str = ft_strjoin(0, NL_chars);

	if (find_NL(NL_chars))
		return(str);
	if (!read_loop(fd, NL_chars, &str))
		return (0);
	return (str);
}

// int main()
// {
//     int fd = open("giant_line_nl.txt", O_RDWR | O_EXCL);

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

//     close(fd);
// }