#include <stdio.h>
#include <math.h>
#include <string.h>
// #define DEBUG
int main(){
    int n;
    char str1[81], str2[81];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", str1);
        scanf("%s", str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int counter = 0;
        // printf("%s %s\n", str1, str2);
        // printf("------------\n");
        if(strcmp(str1,str2) == 0){
            printf("yes\n");
            continue;
        }
        if(len1 == len2){
            int sum = 0, id;
            int i = 0;
            for(i=0;i<len1;i++){
                if(str1[i] == str2[i])
                    sum++;
                else
                    id = i;
            }
            if(sum == len1 - 2 && str1[id] == str2[id-1] && str2[id] == str1[id-1])
                printf("yes\n");
            else
                printf("no\n");
            continue;
        }
        else if(abs(len1 - len2) == 1){
            int sum = 0, flag = 0;
            if(len1 > len2){
                for(int i=0,j=0;i<len2;){
                    if(str1[j] != str2[i] && flag == 0){
                        j++;
                        flag = 1;
                    }
                    if(str1[j] == str2[i]){
                        i++;
                        j++;
                        sum++;
                    }
                    if(str1[j] != str2[i] && flag != 0){
                        i++;
                        j++;
                    }
                }
                if (sum == len2)
                    printf("yes\n");
                else
                    printf("no\n");
            }
            else{ // len2 > len1
                for(int i=0,j=0;i<len1;){
                    if(str2[j] != str1[i] && flag == 0){
                        j++;
                        flag = 1;
                    }
                    else if(str2[j] == str1[i]){
                        i++;
                        j++;
                        sum++;
                    }
                    else if(str2[j] != str1[i] && flag != 0){
                        i++;
                        j++;
                    }
                }
                if (sum == len1)
                    printf("yes\n");
                else
                    printf("no\n");
            }
            continue;
        }
        printf("no\n");
        #ifdef  DEBUG
            printf("%s\n%s\n", str1, str2);
        #endif
    }
    return 0;
}