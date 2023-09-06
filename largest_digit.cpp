#include <stdio.h>
int main(){
    int d0;
    int largest_digit_sum = -1;
    int return_num, largest_number = -1, smaller_digits = 100;
    while(scanf("%d", &d0) != EOF){
        int digit_sum = 0, num  = d0, digits = 0;
        while(!(num == 0)){
            // digit_sum
            int digit = num % 10;
            digit_sum += digit;
            num /= 10;
            // digit
            digits++;
        }
        // 每個數字在進入判斷條件時，要注意條件是否有初始化好
        // 因為我沒有把判斷的條件初始化好，導致再進行新一輪判斷時
        // 我的程式會因為殘流上一次的資料，而導致判斷錯誤
        if(digit_sum > largest_digit_sum){ 
            largest_digit_sum = digit_sum;
            smaller_digits = digits;
            largest_number = d0;
            return_num = d0;  
        }
        else if(digit_sum == largest_digit_sum){
            if(digits < smaller_digits){
                smaller_digits = digits;
                largest_number = d0;
                return_num = d0;
            } // 位數
            else if(digits == smaller_digits){ // 最小位數找最大數
                if(d0 >= largest_number){
                    largest_number = d0;
                    return_num = largest_number;
                }
            //    else
            //         return_num = largest_number;
            }
        }
        // printf("%d %d %d\n", return_num, digit_sum, digits);
        // printf("%d %d\n", largest_number, smaller_digits);
    }
    printf("%d\n", return_num);
    return 0;
}