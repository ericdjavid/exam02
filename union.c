#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//une fonction qui cree une chaine etant la concatenation des 2 chaines
//une fonction qui supprime les lettres en doublons dans la chaine de caracteres

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_concat(char *str1, char *str2)
{
    int s1 = ft_strlen(str1);
    int s2 = ft_strlen(str2);
    int sum = s1 + s2;
    //  printf("\nsum of letter = %d\n", sum);
    char *conc = malloc(sizeof(char) * (sum + 1));

    int i = 0;
    int j = 0;
    while (str1[i])
    {
        conc[j] = str1[i];
        i++;
        j++;
    }
    i = 0;
    while (str2[i])
    {
        conc[j] = str2[i];
        i++;
        j++;
    }
    conc[j] = '\0';

    return (conc);
}

int first_pos(char *str, char c)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int is_other(char *str, char c)
{
    int i = 0;
    int sum = 0;
    while (str[i])
    {
        if (str[i] == c)
            sum += 1;
        i++;
    }
    return sum;
}

char *transform_concat(char *str)
{
    char *neo;
    int i;

    i = 0;
    neo = 0;
    int sl = 0;

    while (str[i])
    {
        if ((sl = is_other(str, str[i])) > 1)
        {
            //printf("\nthere are %d letters\n", sl);
            if (first_pos(str, str[i]) == i)
            {
                write(1, &str[i], 1);
                //printf("\nthis letter is in first post\n");
            }
        }
        else
            write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (neo);
}

int main(int argc, char **argv)
{
    char *concat;
    if (argc != 3)
    {
        write(1, "\n", 2);
        return (-1);
    }
    concat = 0;
    concat = ft_concat(argv[1], argv[2]);
    // printf("\n%s\n", concat);
    transform_concat(concat);

    return 0;
}