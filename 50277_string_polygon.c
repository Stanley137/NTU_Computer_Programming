#include <stdio.h>
#include <limits.h>
#include <string.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int find_offset(char *str,char c){
    return (strchr(str, c) - str);
}
int polygon_sum(char *first_str,int first_offset,char *split_str,char same,int steps,int sum){
    char *str;
    if(steps == 0){
        scanf("%s", str);
        int len = strlen(str);
        int max_sum = INT_MIN;
        for(int i=0;i<len;i++){
            char *p = strchr(first_str, str[i]);
            if(p != NULL)   
                max_sum = max(max_sum, polygon_sum(first_str,(p-first_str),str,str[i],steps+1,sum));
        }
        return max_sum;
    }
    else{
        if(scanf("%s", str)!=EOF){
            int offset0 = find_offset(split_str,same);
            int len = strlen(str);
            int max_sum = INT_MIN;
            for(int i=0;i<len;i++){
                char *p = strchr(split_str, str[i]);
                if(p!=NULL){
                    int offset1 = (p - split_str);
                    int new_sum = (offset1 - offset0);
                    max_sum = max(max_sum, polygon_sum(first_str,first_offset,str,str[i],steps+1,new_sum));
                }
            }
        }
        else{ // in the end compare split_str with first_str
            // split_str
                        
        }
    }

}
int main(){
    char first_str[105], sec_str[105];
    scanf("%s", first_str);
}