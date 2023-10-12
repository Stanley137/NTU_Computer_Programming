#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    int count[26] = {0};
    scanf("%s",str);
    int len = strlen(str);
    for(int i=0;i<len;i++){
        // lower_case
        if(str[i]>=97 && str[i]<=122)
            count[str[i]-97]++;
        // upper_case
        else if(str[i]>=65 && str[i]<=90)
            count[str[i]-65]++;
    }
    for(int i=0;i<26;i++)
        printf("%d\n",count[i]);
    return 0;
}