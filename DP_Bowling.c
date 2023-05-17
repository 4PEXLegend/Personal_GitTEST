#include <stdio.h>

int d[10001];
int bowling[10001];

int main()
{
    int num;
    scanf("%d", &num);

    for(int i = 0; i < num; ++i)
    {
        scanf("%d", &bowling[i]);
    }

    if(bowling[0] > 0)
    {
        d[0] = bowling[0];

    }
    int ans = 0;
    for(int i = 1; i < num; ++i)
    {
        if(i != 1)
        {
            d[i] = ((d[i-1] > d[i-1] + bowling[i] ? d[i-1] : d[i-1] + bowling[i])) > d[i-2] + bowling[i-1] * bowling[i] ? ((d[i-1] > d[i-1] + bowling[i] ? d[i-1] : d[i-1] + bowling[i])) : d[i-2] + bowling[i-1] * bowling[i];
        }
        else{
            d[i] = d[i-1] + bowling[i];
        }
        //d[i-1] + i;; d[i-1];; d[i-2] + i-1 * i;;
    }

    return 0;
}
