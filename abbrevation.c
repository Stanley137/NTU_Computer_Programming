#include <stdio.h>
#include <ctype.h>
#include <string.h>
void empty(char str[], int len){
    for(int i=0;i<len;i++)
        str[i] = '\0';
}
int main(){
    char str[128] ,abbr[128];
    int count = 0, len;
    while(scanf("%s", str) != EOF){
        if(strcmp(str, "of") == 0 || strcmp(str, "and")==0 
        || strcmp(str, "the")==0 || strcmp(str, "at")==0)
            continue;
        if(strcmp(str, "of.") == 0 || strcmp(str, "and.")==0 
        || strcmp(str, "the.")==0 || strcmp(str, "at.")==0){
            printf("\n");
            continue;
        }
        printf("%c", 'A' + (str[0] - 'a'));
        abbr[count] = 'A' + (str[0] - 'a');
        count++;
        len = strlen(str);
        if(str[len-1] == '.'){
            count = 0;
            printf("\n");
            //printf("%s\n", abbr);
            empty(abbr, strlen(abbr));
            // printf("CHECK: %s\n", abbr);
        }
        // printf("DEBUG: %s\n", str);
    }
    return 0;
}