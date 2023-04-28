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
    len = _printf("%");
    printf("\n%d\n", len);
    len = printf("%");
    printf("\n%d\n", len);
    len = _printf("%d", 1024);
    printf("\n%d\n", len);
    len = printf("%d", 1024);
    printf("\n%d\n", len);
    len = _printf("%d", INT_MIN);
    printf("\n%d\n", len);
    len = printf("%d", INT_MIN);
    printf("\n%d\n", len);


    return (0);
}
