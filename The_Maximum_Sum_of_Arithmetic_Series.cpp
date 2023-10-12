#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a1,a0;
    scanf("%d", &a0);
    int sum = a0, max_sum = a0;
    int n_num = 1, max_num = 1;
    int first_num = a0, max_first_num = a0;
    int d;
    int last_d = -1;
    // dealing with input sequence
    for(int i=0;i<n-1;i++){
        scanf("%d", &a1);
        d = a1 - a0;
        // check the same series
        if(d == last_d){
            sum += a1;
            n_num ++;
            //printf("%d %d\n", sum, n_num);
            if(sum > max_sum){
                max_sum = sum;
                max_num = n_num;
                max_first_num = first_num;
            }
            else if(sum == max_sum){
                if(n_num > max_num){
                    max_num = n_num;
                    max_first_num = first_num;
                }
                else if(n_num == max_num){
                    if(first_num > max_first_num)
                        max_first_num = first_num;
                }
            }
        }
        else{
            sum = a0 + a1;
            n_num = 2;
            first_num = a0;
            last_d = d;
        }
        a0 = a1;
    }
    printf("%d %d %d\n", max_sum, max_num, max_first_num);
    return 0;
}