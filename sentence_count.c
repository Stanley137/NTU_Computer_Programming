#include <stdio.h>
#include <string.h>
int main(){
    char str[1000000];
    fread(str, sizeof(char), 1000000, stdin);
    int index =0;
    int count = 0;
    while(str[index] != '\0'){
        if(str[index] == '.'){
            if((str[index+1] == ' ' && str[index+2] == ' ') || (str[index+1] == '\n') || (str[index+1] == '\0'))
                count++;
            // else if((str[index+1] == '\n' && str[index+2] == ' ') || (str[index+1] == ' ' && str[index+2] == '\n'))
            //     count++;
        }
        index++;
    }
    printf("%d\n", count);
    return 0;
}
