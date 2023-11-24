#include <stdio.h>
#include <stdint.h>
uint64_t min(uint64_t a,uint64_t b){
    return (a>b)?b:a;
}

uint64_t find_mini(uint64_t arr[],uint64_t sum[],int i,uint64_t current_sum,int N,int K,uint64_t *min_n){
    if(i==N){
        *min_n = min(*min_n,current_sum); // The deepest, determined by the last
        return *min_n; 
        // return current_sum;
    }
    uint64_t min_sum = UINT64_MAX;
    for(int g=0;g<K;g++){
        uint64_t old_sum = sum[g];
        uint64_t new_sum = current_sum + (2*old_sum*arr[i]) + arr[i]*arr[i];
        if(new_sum < *min_n){
            sum[g] += arr[i];
            min_sum = min(min_sum, find_mini(arr,sum,i+1,new_sum,N,K,min_n));
            sum[g] -= arr[i];
        }
    }
    return min_sum;
}

int main(){
    int N,K;
    uint64_t min = UINT64_MAX;
    uint64_t arr[25];
    uint64_t sum[25] = {0};
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++) scanf("%llu", &arr[i]);
    printf("%llu\n", find_mini(arr,sum,0,0,N,K,&min));
    return 0;
}
