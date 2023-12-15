#include <stdio.h>
#include <assert.h>
#include <stdint.h>

uint64_t min(uint64_t a, uint64_t b)
{
  return (a < b? a : b);
}
  
uint64_t minSumSqu(const uint64_t number[], const int i, 
		   uint64_t sum[], const uint64_t currentSum,
		   const int K, const int N)
{
  if (i == N)
    return currentSum;

  uint64_t minSum = UINT64_MAX;
  for (int g = 0; g < K; g++) {
    uint64_t oldSum = sum[g];
    sum[g] += number[i];
    minSum =
      min(minSum, minSumSqu(number, i + 1, sum,
			    currentSum + 2 * oldSum * number[i] + number[i] * number[i],
			    K, N));
    sum[g] -= number[i];
  }
  return minSum;
}

#define MAXN 20

int main()
{
  int N, K;
  assert(scanf("%d%d", &N, &K) == 2);
  assert(N >= 1 && N <= 20);
  assert(K >= 1 && K <= 10);

  uint64_t number[N];
  for (int i = 0; i < N; i++)
    assert(scanf("%llu", &(number[i])) == 1);

  uint64_t sum[MAXN] = {0};
  printf("%llu\n", minSumSqu(number, 0, sum, 0, K, N));
  return 0;
}