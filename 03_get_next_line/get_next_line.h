#ifndef GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif


size_t	ft_strlen(const char *s);
char    *ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char* get_next_line (int fd);
char	*ft_strchr(const char *s, int c);

#endif