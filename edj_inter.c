#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//une fonction qui cree une chaine etant la concatenation des 2 chaines
//une fonction qui identifie les lettres en doublons dans la chaine de caracteres
// et les affiche

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int find_char(char c, char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (-1);
}

int is_not_before(char c, int pos, char *str)
{
    int i = 0;
    //printf("\n looking for char %c at pos %d\n", c, pos);
    while (i < pos)
    {
        //   printf("\n str[i] is %c\n", str[i]);
        if (str[i] == c)
            return (-1);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "\n", 2);
        return (-1);
    }
    int i = 0;
    while (argv[1][i])
    {
        if (find_char(argv[1][i], argv[2]) != -1)
            if (is_not_before(argv[1][i], i, argv[1]) != -1)
            {
                write(1, &argv[1][i], 1);
            }
        i++;
    }
    return (0);
}
