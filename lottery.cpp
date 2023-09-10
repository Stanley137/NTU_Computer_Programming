#include<stdio.h>
int main(){
    int special_prize[3], first_prize[3];
    for(int i=0;i<3;i++)    scanf("%d", &special_prize[i]);
    for(int i=0;i<3;i++)    scanf("%d", &first_prize[i]);
    int lotter_number, dollars = 0;
    while(scanf("%d", &lotter_number) != EOF){
        int flag = 0;
        for(int i=0;i<3;i++){
            if(lotter_number == special_prize[i]){
                dollars += 2000000;
                flag = 1;
                continue;;
            }
        }
        for(int i=0;i<3;i++){
            if(lotter_number == first_prize[i]){
                dollars += 200000;
                flag = 1;
                continue;
            }
        }
        if(flag)
            continue;
        // printf("%d\n", lotter_number);
        for(int i=0;i<3;i++){
            int digits = 0;
            int num = lotter_number;
            int check_num = first_prize[i];
            // /= 10, might become 0
            while((num % 10) == (check_num % 10) && num > 1 && check_num > 1){
                digits++;
                num /= 10;
                check_num /= 10;
            }
            // printf("%d\n", digits);
            // printf("%d\n", dollars);
            switch(digits){
                case 7:
                    dollars += 40000;
                    break;
                case 6:
                    dollars += 10000;
                    break;
                case 5:
                    dollars += 4000;
                    break;
                case 4:
                    dollars += 1000;
                    break;
                case 3:
                    dollars += 200;
                    break;
            }
        }
        // printf("%d %d %d\n",special_prize[0], special_prize[1], special_prize[2]);
        // printf("%d %d %d\n", first_prize[0], first_prize[1], first_prize[2]);
        // printf("%d\n", dollars);
    }
    printf("%d\n", dollars);
    return 0;
}