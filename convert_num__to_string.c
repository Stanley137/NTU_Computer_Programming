#include <stdio.h>
#include <string.h>
int main(){
    char str_num[1000] = "", str_temp[1000] = "";
    char str1[1000] = "";
    char table_hundred[25][50] = {"","one hundred ", "two hundred ", "three hundred ", "four hundred ", 
    "five hundred ","six hundred ", "seven hundred ", "eight hundred ", "nine hundred "};
    char table2[25][50] = {"","","twenty-", "thirty-", "forty-", "fifty-", "sixty-","seventy-", 
    "eighty-","ninety-"};
    char table1[25][50] = {"", "one ", "two ", "three ", "four ", "five ", "six ", 
    "seven ", "eight ", "nine ","ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
    char table_lion[25][50] = {"","thousand ","million ", "billion ", "trillion ","quadrillion ", "quintillion "};
    long long num;
    long long moder = 1000;
    int count = 0;
    scanf("%lld", &num);
    while(num >=1){
        int thousand_n = num % 10000 / moder; // 1234, 1 
        int parse_num  = num % 1000; // 12345, 2345
        int hundred_n = parse_num / 100; // 1234, 2
        int ten_num_n = num % 100; // 1234, 34
        strcpy(str1, table_hundred[hundred_n]);
        if(ten_num_n <= 19){
            strcat(str1, table1[ten_num_n]);
        }
        else{
            int ten_num = ten_num_n / 10;
            int one_num = ten_num_n % 10;
            strcat(str1, table2[ten_num]);
            strcat(str1, table1[one_num]);
        }
        strcpy(str_temp, str_num);
        strcpy(str_num, str1); // 123456, old_move 456, cpy 123
        strcat(str_num, table_lion[count]); // here is the key
        strcat(str_num, str_temp); // 
        printf("count: %d\n", count);
        printf("str_num: %s\n", str_num);
        printf("str1: %s\n",str1);
        count++;
        num /= moder;
    }
    printf("%s\n", str_num);
    return 0;
}
