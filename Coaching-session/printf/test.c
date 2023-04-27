#include "main.h"

int main(void)
{
    int len;

    len = _printf("%c love %s %s is my %s", 'I', "David", "he", NULL);
    printf("%d\n", len);
    len = printf("%c love %s %s is my %s", 'I', "David", "he", NULL);
    printf("%d\n", len);
    len = _printf("%s\n", NULL);
    printf("%d\n", len);
    len = printf("%s\n", NULL);
    printf("%d\n", len);
    len = _printf("%c\n", 'A');
    printf("%d\n", len);
    len = printf("%c\n", 'A');
    printf("%d\n", len);
    len = _printf("%%\n");
    printf("%d\n", len);
    len = printf("%%\n");
    printf("%d\n", len);


    return (0);
}
