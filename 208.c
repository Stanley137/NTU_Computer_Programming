#include <stdio.h>
int main(){
    int row ,col;
    scanf("%d%d", &row, &col);
    char c0[2], c1[2];
    scanf("%s%s", c1, c0);
    int limit = row*col;
    unsigned int num;
    char print[limit];
    int index = 0;
    while(scanf("%d", &num)!=EOF){
        for(int i=31;i>=0;i--){
            if(num&(unsigned int)(1<<31))
                print[index] = c1[0];
            else
                print[index] = c0[0];
            index++;
            if(index==limit)
                break;
            num = num << 1;
        }
    }
    for(int i=0;i<limit;i++){
        if((i+1)%row==0)
            printf("%c\n", print[i]);
        else
            printf("%c", print[i]);
    }
    return 0;
}