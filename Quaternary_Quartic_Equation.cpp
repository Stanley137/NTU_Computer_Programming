#include <stdio.h>
int one_f(int a, int b, int c, int d)
{
    return a + b + c + d;
}
int two_f(int a, int b, int c, int d)
{
    return a * a + b * b + c * c + d * d;
}
int three_f(int a, int b, int c, int d)
{
    return a * a * a + b * b * b + c * c * c + d * d * d;
}
int four_f(int a, int b, int c, int d)
{
    return a * a * a * a + b * b * b * b + c * c * c * c + d * d * d * d;
}
int main()
{
    int one, two, three, four;
    scanf("%d%d%d%d", &one, &two, &three, &four);
    int a = one - 6, b = 3, c = 2, d = 1;
    for (int x = a; x > b; x--)
    {
        for (int y = b; y > one - x - y - 1; y--) //  here is the key
        {  // for each y, has to run one times to search z, k
            for (int z = one - x - y - 1; z > one - x - y - z; z--) // 解二元
            {
                int k = one - x - y - z;
                if (one_f(x, y, z, k) == one && two_f(x, y, z, k) == two && three_f(x, y, z, k) == three && four_f(x, y, z, k) == four)
                {
                    printf("%d\n%d\n%d\n%d\n", x, y, z, k);
                    return 0;
                }
            }
        }
        b++;
    }
    printf("-1\n");
    return 0;
}