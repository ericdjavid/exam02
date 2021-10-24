#include <stdio.h>

int ft_printf(char *, ...);

int main(void)
{
    int ret = 0;
    int d = 14;
    int dnul = 0;
    char *s = "this is fcking char*";
    char *snul = 0;
    int xnul = 0;
    int x = 8430845;

    ret = printf("\n--Mother printf--\n");
    printf("\nret is %d\n", ret);
    ret = printf("\nd is %d, and dnul is %d\n", d, dnul);
    printf("\nret is %d\n", ret);
    ret = printf("\nx is %x, and xnul is %x\n", x, xnul);
    printf("\nret is %d\n", ret);
    ret = printf("\ns is |%s|, and snul is %s\n", s, snul);
    printf("\nret is %d\n", ret);
    ret = ft_printf("\n--Son ft_printf--\n");
    ft_printf("\nret is %d\n", ret);
    ret = ft_printf("\nd is %d, and dnul is %d\n", d, dnul);
    ft_printf("\nret is %d\n", ret);
    ret = ft_printf("\nx is %x, and xnul is %x\n", x, xnul);
    printf("\nret is %d\n", ret);
    ret = ft_printf("\ns is |%s|, and snul is %s\n", s, snul);
    ft_printf("\nret is %d\n", ret);

    ft_printf("\n% and %% are now printed\n");
    return 0;
}