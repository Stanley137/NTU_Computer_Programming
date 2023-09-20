#include <stdio.h>
int min(int a, int b)
{
    return (a > b) ? b : a;
}
int main()
{
    int N, M, k;
    scanf("%d%d%d", &N, &M, &k);
    int rounds = min(N, M);
    int i = 1;
    for (int r = 1; r <= rounds; r++)
    {
        // check width
        int width = M - r + 1;
        if (k >= i && k < i + width)
        {
            printf("%d %d\n", r, k - i + r);
            return 0;
        }
        // check height
        i += width;
        if (r < N) // Under any circumstances, check left to right will be the last
        {           // 
            int height = N - r;
            if (k >= i && k < i + height)
            {
                printf("%d %d\n", k - i + 1 + r, r);
                return 0;
            }
            i += height;
        }
    }
    return 0;
}