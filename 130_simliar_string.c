#include <stdio.h>
#include <math.h>
#include <string.h>
#define DEBUG
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
        if(strcmp(str1,str2) == 0){
            printf("yes\n");
            continue;
        }
        if(len1 == len2){
            for(int i=1;i<=n-2;i++){ // check switching
                if(str1[i] != str2[i]){
                    if(str1[i-1] == str2[i] || str1[i+1] == str2[i])
                        continue;
                    break;
                }
            }
        }
        else if(abs(len1 - len2) == 1){
            
        }
        #ifdef  DEBUG
            printf("%s\n%s\n", str1, str2);
        #endif
    }
    return 0;
}