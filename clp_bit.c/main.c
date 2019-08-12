#include <stdio.h>
#include <stdlib.h>

#define CPL_BIT(x, n) ((x) ^= (1<<n))
int main()
{
    int x = 0xFF;
    CPL_BIT(x, 5);
    printf("%d\n\n", x);
    {
        for (int i = 8*(sizeof(int)) - 1; 0 <= i; i--)
        {
            printf("%c", (x & (1 << i)) ? '1' : '0');
            if (!(i % 8))
                printf(" ");
        }
    }
    return 0;
}
