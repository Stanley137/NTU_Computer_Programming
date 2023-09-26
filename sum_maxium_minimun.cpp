#include <stdio.h>
#include <limits.h>
int main()
{
    long long N, n, m;
    long long r_smm[15000][3];
    scanf("%lld%lld", &N, &m);
    for(int i=0;i<N;i++) r_smm[i][0] = 0;
    for(int i=0;i<N;i++) r_smm[i][1] = INT_MIN;
    for(int i=0;i<N;i++) r_smm[i][2] = INT_MAX;
    
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &n);
        int r_i = n % m;
        // printf("%lld %lld\n",n, r_i);
        r_smm[r_i][0] += n;
        if (n > r_smm[r_i][1])
            r_smm[r_i][1] = n;
        if(n < r_smm[r_i][2]    )
            r_smm[r_i][2] = n;
        // printf("%d %d\n", n, i);
    }
    // printf("Out\n");
    for (int i = 0; i < m; i++)
        printf("%lld %lld %lld\n", r_smm[i][0], r_smm[i][1], r_smm[i][2]);
    return 0;
}