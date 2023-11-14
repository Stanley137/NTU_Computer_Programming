#include <stdio.h>
#include <string.h>
#define N 100000
#define L 26
int main(){
    char word[N];
    int f[L][L][L] = {{{0}}};
    while(scanf("%s", word) != EOF){
        int len = strlen(word);
        if(len<3)
            continue;
        else{
            int index = 0;
            while(word[index+2]!='\0'){
                f[word[index] - 'a'][word[index+1] - 'a'][word[index+2] - 'a']++;
                index++;
            }
        }
    }
    for(int n=0;n<3;n++){
        int max_0 = 0,max_1 = 0,max_2 = 0,max = -1;
        for(int i=0;i<L;i++){
            for(int j=0;j<L;j++){
                for(int k=0;k<L;k++){
                    if(f[i][j][k] > max){
                        max = f[i][j][k];
                        max_0 = i;
                        max_1 = j;
                        max_2 = k;
                    }
                }
            }
        }
        printf("%c%c%c\n",max_0+'a', max_1+'a',max_2+'a');
        f[max_0][max_1][max_2] = -1;
    }
}