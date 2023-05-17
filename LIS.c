#include <stdio.h>

int main()
{
    int input[1001] = {0, };
    int num;
    int d[1001] = {0, };
    scanf("%d", &num);
    for(int i = 0; i < num; ++i)
    {
        scanf("%d", &input[i]);
    }
    int max = 0;
    int ans = 0;
    for(int i = 0; i < num; ++i)
    {
        max = 0;
        for(int j = 0; j < i; ++j)
        {
            if(input[j] < input[i])
            {
                max = max > d[j] ? max : d[j];
            }
        }
        d[i] = max + 1;
        ans = ans > d[i] ? ans : d[i];
    }
    for(int i = 0; i < num; ++i) printf("%d ", d[i]);
    printf("\n%d\n", ans);
    return 0;
}
