#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
//#define BUFFER_SIZE 1

#define $END_LINE '\n'
#define $END '\0'

int ft_strlen_c(char *str, char c)
{
    int i = 0;
    if (!str)
        return (-1);
    if (c == $END)
    {
        while (str[i])
            i++;
        return (i);
    }
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

char *ft_strdup(char *str, int n)
{
    int i = 0;
    if (!str)
        return 0;
    while (str[i] && i < n)
        i++;
    char *tmp;
    tmp = malloc(sizeof(char) * i + 1);
    if (!tmp)
        return (NULL);
    i = 0;
    while (str[i] && i < n)
    {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = $END;
    return tmp;
}

char *ft_join(char *str1, char *str2)
{
    if (!str1 || !str2)
        return (0);
    char *tmp;

    int size = ft_strlen_c(str1, 0) + ft_strlen_c(str2, 0) + 1;
    tmp = malloc(sizeof(char) * size);
    int i = 0;
    int j = 0;
    while (str1[i])
    {
        tmp[i] = str1[i];
        i++;
    }
    free(str1);
    while (str2[j])
    {
        tmp[i] = str2[j];
        j++;
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char *get_return(char **delta)
{
    char *temp;
    char *line;
    const int pos = ft_strlen_c(*delta, $END_LINE);
    line = NULL;
    if (pos != -1)
    {
        line = ft_strdup(*delta, pos + 1);
        temp = *delta;
        *delta = ft_strdup(*delta + pos + 1, ft_strlen_c(*delta + pos + 1, $END));
        free(temp);
    }
    else if (*delta)
    {
        line = ft_strdup(*delta,
                         ft_strlen_c(*delta, '\0'));
        free(*delta);
        *delta = NULL;
    }
    return (line);
}

char *get_next_line(int fd)
{
    static char *delta;
    char buff[BUFFER_SIZE + 1];
    int ret = 0;

    while (ft_strlen_c(delta, $END_LINE) == -1)
    {
        ret = read(fd, buff, BUFFER_SIZE);
        if (ret <= 0)
            break;
        buff[ret] = $END;
        if (!delta)
            delta = ft_strdup(buff,
                              ft_strlen_c(buff, '\0'));
        else
            delta = ft_join(delta, buff);
    }
    return (get_return(&delta));
}

int main(int argc, char **argv)
{
    int fd;
    char *line;
    if (argc != 2)
    {
        printf("pbm with arg\n");
        return (0);
    }
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf("problem in opening file\n");
        return (2);
    }
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    // close(fd);
    return (0);
}