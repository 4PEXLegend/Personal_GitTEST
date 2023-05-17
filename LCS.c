#include <stdio.h>
#include <string.h>

char input[10001];
char comp[10001];
int d[10001][10001];

int main()
{
    int n,m;
    scanf("%s", input);
    scanf("%s", comp);
    n = strlen(input);
    m = strlen(comp);
    int ans = 0;
    int j = 1;
    for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) d[i][j] = 0;
    //c[i,j] = c[i-1, j-1] + 1 or max c[i, j-1] , c[i-1, j]
    if(input[0] == comp[0]) d[0][0] = 1;
    for(int i = 1; i < m; ++i)
    {
        for(j = 1; j < n; ++j)
        {
            if(input[j] == comp[i])
            {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else
            {
                d[i][j] = d[i-1][j] > d[i][j-1] ? d[i-1][j] : d[i][j-1];
            }
        }
        ans = ans > d[i][j] ? ans : d[i][j];
    }
    for(int i = 0; i < m; ++i)
    {
        for(int k = 0; k < n; ++k)
        {
            printf("%d ", d[i][k]);
        }
        printf("\n");
    }
    printf("%d\n", ans);
    return 0;
}
