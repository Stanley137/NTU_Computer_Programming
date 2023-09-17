#include <stdio.h>
#include <math.h>
//#define DEBUG 1
int main()
{
    int park[100][4];
    int n, m;
    int x1, y1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &park[i][0], &park[i][1], &park[i][2]);
        park[i][3] = 0;
    }
    scanf("%d", &m);
    int smallest_i = 0;
    int smallest_d = 200000000;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x1, &y1);
        for (int j = 0; j < n; j++)
        {
            if (park[j][2] > 0)
            {
                int d = abs(park[j][0] - x1) + abs(park[j][1] - y1);
                if (d < smallest_d)
                {
                    smallest_d = d;
                    smallest_i = j;
                }
                else if (d == smallest_d)
                {
                    if (park[j][0] < park[smallest_i][0])
                        smallest_i = j;
                    else if (park[j][0] == park[smallest_i][0])
                    {
                        if (park[j][1] < park[smallest_i][1])
                            smallest_i = j;
                    }
                }
            }
        }
        park[smallest_i][3]++;
        park[smallest_i][2]--;
        smallest_d = 200000000; // new input, new smallest_d
        #ifdef DEBUG
            printf("smallest: park%d\n", smallest_i);
            for (int k = 0; k < n; k++)
            {
                printf("park%d: %d %d %d %d\n", k, park[k][0], park[k][1], park[k][2], park[k][3]);
            }
        #endif
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", park[i][3]);
    return 0;
}