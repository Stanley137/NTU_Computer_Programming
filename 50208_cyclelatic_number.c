#include <stdio.h>
#include <string.h>
int find_cc(char *str0, char *cn_str[]){
    for(int i=0;i<5;i++){
        if(strcmp(str0, cn_str[i]) == 0){
            //printf("DEBUG: find: %s\n", cn_str[i]);
            return 1;
        }else{
            int len = strlen(str0);
            for(int i=0;i<len;i++){
                if(str0[i] == '?'){
                    //printf("DEBUG: find: ?\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}
int parse_program(char *str, char parse[10]){
    char *cn_str[10] = {"for", "while", "if","case", "?"};
    int cc_num = 0;
    char *str0 = strtok(str, parse);
    while(str0 != NULL){
        if(find_cc(str0, cn_str))
            cc_num++;
        //printf("%s\n", str0);
        str0 = strtok(NULL, parse);
    }
    return cc_num;
}
int main(){
    char program[30000], *str, parse[10] = " \t\n(){";
    str = strtok(program, parse);
    int cc = 0;
    while(fgets(program, 30000, stdin) != NULL){
        cc += parse_program(program, parse);
    }
    printf("%d\n", cc);
    return 0;
}