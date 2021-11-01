#include <stdio.h>
#include <limits.h>

int ft_printf(char *, ...);

int main(void)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int ret = 0;
    int d = -2147484000;
    int dnul = 2147483648;
    char *s = "this is fcking char*";
    char *snul = 0;
    int xnul = 0;
    int x = 8430845;

    ret = printf("\n--Mother printf--\n");
    printf("\nret is %d\n", ret);
    ret = printf("\nint min is %d, and int max is %d\n", d, dnul);
    printf("\nret is %d\n", ret);
    ret = printf("\nx is %x, and x nul is %x\n", x, xnul);
    printf("\nret is %d\n", ret);
    ret = printf("\ns is |%s|, and s nul is %s\n", s, snul);
    printf("\nret is %d\n", ret);
    ret = ft_printf("\n--Son ft_printf--\n");
    ft_printf("\nret is %d\n", ret);
    ret = ft_printf("\nd is %d, and d nul is %d\n", d, dnul);
    ft_printf("\nret is %d\n", ret);
    ret = ft_printf("\nx is %x, and x nul is %x\n", x, xnul);
    printf("\nret is %d\n", ret);
    ret = ft_printf("\ns is |%s|, and s nul is %s\n", s, snul);
    ft_printf("\nret is %d\n", ret);

    ret = ft_printf("\n% and %% are now printed\n");
    ft_printf("\nret is %d\n", ret);
    return 0;
}