#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_putstr(char *str)
{
    if (!str)
    {
        write(1, "(null)", 6);
        return (6);
    }
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int process_d(int d)
{
    if (!d)
    {
        write(1, "0", 1);
        return 1;
    }
    int sign = 0;
    if (d < 0)
    {
        sign = 1;
        d *= -1;
    }
    int d2 = d;
    int count = 0;
    while (d2 > 0)
    {
        d2 /= 10;
        count++;
    }
    char *str = malloc(sizeof(char) * (count + 1));
    str[count] = '\0';
    while (count--)
    {
        str[count] = '0' + (d % 10);
        d /= 10;
    }

    int ret = 0;
    if (sign)
    {
        write(1, "-", 1);
        ret += 1;
    }
    ret += ft_putstr(str);
    free(str);
    return (ret);
}

int process_s(char *str)
{
    int ret = ft_putstr(str);
    return (ret);
}

int process_x(unsigned int x)
{
    char *hex = "0123456789abcdef";
    if (!x)
    {
        write(1, "0", 1);
        return 1;
    }
    unsigned int x2 = x;
    int count = 0;
    while (x2 > 0)
    {
        x2 /= 16;
        count++;
    }
    char *str = malloc(sizeof(char) * (count + 1));
    str[count] = '\0';
    while (count--)
    {
        str[count] = hex[x % 16];
        x /= 16;
    }
    int ret = ft_putstr(str);
    free(str);
    return ret;
}

int ft_printf(char *str, ...)
{
    va_list lol;

    va_start(lol, str);
    int i = 0;
    int ret = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            if (str[i + 1] == 'd')
                ret += process_d(va_arg(lol, int));
            else if (str[i + 1] == 's')
                ret += process_s(va_arg(lol, char *));
            else if (str[i + 1] == 'x')
                ret += process_x(va_arg(lol, unsigned int));
            //added from last exam version
            else
            {
                write(1, "%", 1);
                i++;
                continue;
            }
            i++;
        }
        else
        {
            write(1, &str[i], 1);
            ret += 1;
        }
        i++;
    }
    va_end(lol);
    return (ret);
}