#include <stdio.h>
#include <string.h>
int main(){
    char num[1000];
    while(1){
        scanf("%s", num);
        if(strcmp(num, "-1") == 0)
            break;
        int len = strlen(num);
        // check two
        int last_digits = num[len-1] - '0';
        if(last_digits % 2 == 0)
            printf("yes ");
        else
            printf("no ");
        // check three
        int digits_sum = 0;
        for(int i=0;i<len;i++)
            digits_sum += (num[i] - '0');
        if(digits_sum % 3 == 0)
            printf("yes ");
        else
            printf("no ");
        // check five
        if(last_digits % 5 == 0)
            printf("yes ");
        else
            printf("no ");
        // check eleven
        if(len == 1)
            printf("no\n");
        else{
            int flag = 0;
            int sum = 0;
            for(int i=0;i<len;i++){
                if(flag)
                    sum += (num[i] - '0');
                else
                    sum -= (num[i] - '0');
                flag = !flag; 
            }
            if(sum % 11 == 0)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    // printf("Out");
    return 0;
}