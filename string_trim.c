#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char str[200];
    while(fgets(str, 100, stdin) != NULL){
        int len = strlen(str);
        int f_offset = 0, b_offset;
        // printf("%d\n", len);
        // backward
        for(b_offset=len-2;b_offset>=0;b_offset--){
            if(!isspace(str[b_offset])){
                break;
            }
        }
        int flag = 1;
        for(int i=0;i<=b_offset;i++){
            if(isspace(str[i]) && flag)
                continue;
            else
                flag = 0;
            if(isspace(str[i]) && !flag || !isspace(str[i]))
                printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}