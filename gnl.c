#include "get_next_line.h"
size_t ft_strlen(char *str)
{
    size_t i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}
char *ft_strchr(char *str, int c)
{
    size_t i = 0;
    if (!str)
        return (NULL);
    while (str[i])
    {
        if (str[i] == c)
            return (&str[i]);
        i++;
    }
    if (str[i] == c)
        return (&str[i]);
    return (NULL);
}
char *ft_strjoin(char *s1, char *s2)
{
    char *ret;
    size_t i = 0, e = 0;
    if (!s1)
    {
        s1 = malloc(1);
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
    if (!s2)
        return (NULL);
    ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!ret)
        return (NULL);
    while (s1[i])
    {
        ret[i] = s1[i];
        i++;
    }
    while (s2[e])
    {
        ret[i] = s2[e];
        e++;
        i++;
    }
    ret[i] = '\0';
    free(s1);
    return (ret);
}
char *ft_read(int fd, char *stat)
{
    int ret = 1;
    char buf[BUFFER_SIZE + 1];
    while (ret != 0 && !ft_strchr(stat, '\n'))
    {
        ret = read(fd, buf, BUFFER_SIZE);
        if (ret == -1)
            return (NULL);
        buf[ret] = '\0';
        stat = ft_strjoin(stat, buf);
    }
    return (stat);
}

char *get_line(char *stat)
{
    char *ret;
    size_t i = 0;
    if (!stat[0])
        return (NULL);
    ret = malloc(ft_strlen(stat) + 2);
    if (!ret)
        return (NULL);
    while (stat[i] && stat[i] != '\n')
    {
        ret[i] = stat[i];
        i++;
    }
    if (stat[i] == '\n')
    {
        ret[i] = '\n';
        i++;
    }
    ret[i] = '\0';
    return (ret);
}

char *ft_stat(char *stat)
{
    size_t i = 0, e = 0;
    char *ret;
    while (stat[i] && stat[i] != '\n')
        i++;
    if (!stat[i]) //si le buffer se finit sans qu'il y ait de '\n'
    {
        free(stat);
        return (NULL);
    }
    //tu retournes la différence entre le \n et la fin du buffer dans static
    ret = malloc(ft_strlen(stat) - i + 1);
    if (!ret)
        return (NULL);
    i++;
    while (stat[i])
    {
        ret[e] = stat[i];
        i++;
        e++;
    }
    ret[e] = '\0';
    free(stat);
    return (ret);
}

char *get_next_line(int fd)
{
    char *line;
    static char *stat;
    if (BUFFER_SIZE < 1 || fd < 0)
        return (NULL);
    stat = ft_read(fd, stat);
    if (!stat)
        return (NULL);
    line = get_line(stat);
    stat = ft_stat(stat);
    return (line);
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
    close(fd);
    return (0);
}