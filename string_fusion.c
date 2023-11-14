#include <stdio.h>
#include <string.h>
int main(){
    char str1[200], fusion[400], slice[200];
    scanf("%s", fusion);
    while(scanf("%s", str1) != EOF){
        // check the same
        int len_fusion = strlen(fusion);
        int len1 = strlen(str1);
        int flag = 1, offset = -1;
        for(int start=len_fusion-1;start>=0;start--){
            flag = 1;
            for(int i=0;i+start<len_fusion;i++){ // check pattern
                if(fusion[i+start] != str1[i]){
                    flag = 0;
                    break;
                }
            }
            if(flag)
                offset = len_fusion - 1 -start;
            // printf("%d\n", offset);
        }
        strcpy(slice, str1+offset+1);
        strcat(fusion, slice);
    }
    printf("%s\n", fusion);
    return 0;
}