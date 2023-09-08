#include <stdio.h>
int main(){
    int n, num;
    int n3=0, n3_1=0,n3_2=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &num);
        if(num%3==0)
            n3+=1;
        else if(num%3==1)
            n3_1+=1;
        else if(num%3==2)
            n3_2+=1;
    }
    printf("%d %d %d\n", n3,n3_1,n3_2);
    return 0;
}