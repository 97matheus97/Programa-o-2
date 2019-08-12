#include <stdio.h>
#include <stdlib.h>

#define SET_BIT(x, n) ((x) = (x)|(1 << (n)) ) //x |= (1 << n)

int main()
{
    char x = 4;
    int n = 5;
    SET_BIT(x, n);
    printf("%d\n\n", x);
    for (int i = 8*(sizeof(int)) - 1; 0 <= i; i--)
    {
        printf("%c", (x & (1 << i)) ? '1' : '0');
        if (!(i % 8))
            printf(" ");
    }

    return 0;
}
