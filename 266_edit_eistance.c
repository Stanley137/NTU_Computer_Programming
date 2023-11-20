#include <stdio.h>
#include <string.h>
#include <limits.h>
struct String
{
    char str[15];
    int id;
};
typedef struct String string;

int min(int a,int b){
    return (a>b)? b:a;
}

int distance(char *str1,char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 == 0 && len2 == 0)
        return 0;
    if(len1 == 0 && len2 != 0)
        return len2;
    if(len1 !=0 && len2 == 0)
        return len1;
    if(str1[0] == str2[0]){
        str1+=1;
        str2+=1;
        return distance(str1,str2);
    }
    else
        return 1 + min(distance(str1,str2+1),distance(str1+1,str2));
}

int main(){
    string str_structs[100];
    int idx_counter = 2;
    int i=3,min_index1,min_index2;
    int dis,min_dis;
    scanf("%s", str_structs[1].str); str_structs[1].id = 1;
    scanf("%s", str_structs[2].str); str_structs[2].id = 2;
    dis = distance(str_structs[1].str,str_structs[2].str);
    min_dis = dis;
    min_index1 = 1; min_index2=2;
    while(scanf("%s", str_structs[i].str) != EOF){
        str_structs[i].id = i;
        // counter pattern
    }  
    return 0;
}